#include "DrinkMachine.h"
#include "Source.h"

const int main()
{
	double* drinkPrice1 = new double{ .75 }, * drinkPrice2 = new double{ .80 };
	int defaultDrinkStock = 20;
	char* drinkName1 = new char[(strlen("Cola") + 1)], * drinkName2 = new char[(strlen("Root Beer") + 1)], * drinkName3 = new char[(strlen("Lemon-Lime") + 1)], * drinkName4 = new char[(strlen("Grape Soda") + 1)], * drinkName5 = new char[(strlen("Cream Soda") + 1)];

	defaultDrinks(drinkName1, drinkName2, drinkName3, drinkName4, drinkName5);

	DrinkMachine* allDrinks[]
	{
		new DrinkMachine{drinkName1, drinkPrice1, defaultDrinkStock },
		new DrinkMachine{drinkName2, drinkPrice1, defaultDrinkStock},
		new DrinkMachine{drinkName3, drinkPrice1, defaultDrinkStock},
		new DrinkMachine{drinkName4, drinkPrice2, defaultDrinkStock},
		new DrinkMachine{drinkName5, drinkPrice2, defaultDrinkStock}
	};

	cout << "\nWelcome to Enigmatic's Engineer Drink Machine!";
	
	int optionSelected{};
	do
	{
		chooseDrink(allDrinks, optionSelected);

		enum Drinks
		{
			DRINK1 = 1,
			DRINK2 = 2,
			DRINK3 = 3,
			DRINK4 = 4,
			DRINK5 = 5
		};

		double drinkPayment{}, total{};

		switch (optionSelected)
		{
		case DRINK1:
			checkStock(allDrinks, optionSelected, drinkPayment, total);
			adjustQuantity(allDrinks, optionSelected);
			break;

		case DRINK2:
			checkStock(allDrinks, optionSelected, drinkPayment, total);
			adjustQuantity(allDrinks, optionSelected);
			break;

		case DRINK3:
			checkStock(allDrinks, optionSelected, drinkPayment, total);
			adjustQuantity(allDrinks, optionSelected);
			break;

		case DRINK4:
			checkStock(allDrinks, optionSelected, drinkPayment, total);
			adjustQuantity(allDrinks, optionSelected);
			break;

		case DRINK5:
			checkStock(allDrinks, optionSelected, drinkPayment, total);
			adjustQuantity(allDrinks, optionSelected);
			break;

		default:
			cout << "\nExiting program...";
		}

	} while (optionSelected != 6);
	
	wipeHeapMemory(drinkPrice1, drinkPrice2, drinkName1, drinkName2, drinkName3, drinkName4, drinkName5);

	cout << "\n\n";
	return 0;
}

void defaultDrinks(char* drinkName1, char* drinkName2, char* drinkName3, char* drinkName4, char* drinkName5)
{
	strcpy_s(drinkName1, (strlen("Cola") + 1), "Cola");
	strcpy_s(drinkName2, (strlen("Root Beer") + 1), "Root Beer");
	strcpy_s(drinkName3, (strlen("Lemon-Lime") + 1), "Lemon-Lime");
	strcpy_s(drinkName4, (strlen("Grape Soda") + 1), "Grape Soda");
	strcpy_s(drinkName5, (strlen("Cream Soda") + 1), "Cream Soda");
}

void chooseDrink(DrinkMachine* allDrinks[5], int& optionSelected)
{
	cout << "\n\n\nThe available beverages are:"
		<< "\n___________________________________________________________"
		<< "\nDrink Name \t\tCost \t\tQuantity in Machine"
		<< "\n___________________________________________________________"
		<< "\n\n1. " << allDrinks[0]->getDrinkName() << "\t\t\t" << *allDrinks[0]->getDrinkPrice() << "$\t\t\t" << allDrinks[0]->getDrinkQuantity()
		<< "\n2. " << allDrinks[1]->getDrinkName() << "\t\t" << *allDrinks[1]->getDrinkPrice() << "$\t\t\t" << allDrinks[1]->getDrinkQuantity()
		<< "\n3. " << allDrinks[2]->getDrinkName() << "\t\t" << *allDrinks[2]->getDrinkPrice() << "$\t\t\t" << allDrinks[2]->getDrinkQuantity()
		<< "\n4. " << allDrinks[3]->getDrinkName() << "\t\t" << *allDrinks[3]->getDrinkPrice() << "$\t\t\t" << allDrinks[3]->getDrinkQuantity()
		<< "\n5. " << allDrinks[4]->getDrinkName() << "\t\t" << *allDrinks[4]->getDrinkPrice() << "$\t\t\t" << allDrinks[4]->getDrinkQuantity()
		<< "\n___________________________________________________________"
		<< "\n\n\tChoose by entering the Drink Number (Enter '6' if you want to QUIT) --> ";
	cin >> optionSelected;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\nSorry, only integer values accepted, re-enter --> ";
		cin >> optionSelected;
	}

	while (optionSelected < 1 || optionSelected > 6)
	{
		cout << "\nSorry, please select a valid number --> ";
		cin >> optionSelected;
	}
}

void wipeHeapMemory(double*& drinkPrice1, double*& drinkPrice2, char*& drinkName1, char*& drinkName2, char*& drinkName3, char*& drinkName4, char*& drinkName5)
{
	delete drinkPrice1;
	drinkPrice1 = nullptr;

	delete drinkPrice2;
	drinkPrice2 = nullptr;

	delete[] drinkName1;
	drinkName1 = nullptr;

	delete[] drinkName2;
	drinkName2 = nullptr;

	delete[] drinkName3;
	drinkName3 = nullptr;

	delete[] drinkName4;
	drinkName4 = nullptr;

	delete[] drinkName5;
	drinkName5 = nullptr;
}

void checkStock(DrinkMachine* allDrinks[5], int& optionSelected, double& drinkPayment, double& total)
{
	if (allDrinks[--optionSelected]->getDrinkQuantity() < 1)
	{
		cout << "\nThis beverage is out of stock!";
	}
	else
	{
		buyDrink(drinkPayment, total, allDrinks, optionSelected);
	}

	if (total > *allDrinks[optionSelected]->getDrinkPrice())
	{
		cout << "\nRefunding the next amount --> $ " << (total - *allDrinks[optionSelected]->getDrinkPrice())
			<< "\nPick up your drink!";
	}
}

void adjustQuantity(DrinkMachine* allDrinks[5], int optionSelected)
{
	allDrinks[optionSelected]->setDrinkQuantity((allDrinks[optionSelected]->getDrinkQuantity() - 1));
}

void buyDrink(double& drinkPayment, double& total, DrinkMachine* allDrinks[5], int optionSelected)
{
	cout << "\nEnter quantity (Do not go below $0 nor above $1) --> $";
	cin >> drinkPayment;

	while (drinkPayment < 0.0 || drinkPayment > 1.0 || cin.fail())
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\nSorry, only double values accepted, re-enter --> $";
			cin >> drinkPayment;
		}
		else
		{
			cout << "\nSorry, please enter a valid quantity --> $";
			cin >> drinkPayment;
		}
	}

	total += drinkPayment;
	while (*allDrinks[optionSelected]->getDrinkPrice() > total)
	{
		cout << "\nThe total so far is --> $" << total;
		cout << "\nEnter missing amount ($" << (*allDrinks[optionSelected]->getDrinkPrice() - total) << ") --> $";
		cin >> drinkPayment;
		doubleValuesValidation(drinkPayment);

		while (drinkPayment > 1.0)
		{
			cout << "\nQuantity exceeded, refunding amount..."
				<< "\nRe-enter valid quantity --> $";
			cin >> drinkPayment;
			doubleValuesValidation(drinkPayment);
		}

		total += drinkPayment;
	}
}

void doubleValuesValidation(double& drinkPayment)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\nSorry, only double values accepted, re-enter --> ";
		cin >> drinkPayment;
	}
}