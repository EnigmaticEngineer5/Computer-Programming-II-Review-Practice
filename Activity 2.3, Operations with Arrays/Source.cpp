#include "InventoryClass.h"
#include "Source.h"

const int main()
{
	cout << "\n\t- How many items do you want to store in the inventory? --> ";
	int itemCount{};
	cin >> itemCount;

	while (cin.fail() || itemCount < 1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\nInvalid entry, re-enter valid amount of items --> ";
		}
		else
		{
			cout << "\nNo negative values accepted, re-enter --> ";
		}

		cin >> itemCount;
	}

	unique_ptr<Inventory[]> AllItems(new Inventory[itemCount]);

	for (size_t i{}; i < itemCount; i++)
	{
		cout << "\nItem #" << (i + 1)
			<< "\n\t- Enter the ITEM NUMBER --> ";
		int itemNumber{};
		cin >> itemNumber;
		inputValidation(itemNumber);

		cout << "\t- Enter the ITEM QUANTITY --> ";
		int itemQuantity{};
		cin >> itemQuantity;
		inputValidation(itemQuantity);

		cout << "\t- Enter the ITEM COST --> $";
		double itemCost{};
		cin >> itemCost;
		inputValidation2(itemCost);

		AllItems[i].setItemNumber(itemNumber).setQuantity(itemQuantity).setCost(itemCost);
	}

	enum MyEnum
	{
		AddItem = 1,
		RemoveItem = 2,
		ModifyItem = 3,
		PrintContents = 4
	};

	int optionSelected{};

	do
	{
		cout << "\n\nDo you want to:"
			<< "\n\t 1) Add Item"
			<< "\n\t 2) Remove Item"
			<< "\n\t 3) Modify Item"
			<< "\n\t 4) Print Contents"
			<< "\n\t 5) Quit program"
			<< "\n--> ";
		cin >> optionSelected;

		while (cin.fail() || optionSelected < 1 || optionSelected > 5)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "\nPlease enter a valid option of the menu --> ";
			}
			else if (optionSelected < 1 || optionSelected > 5)
			{
				cout << "\nPlease re-enter a value between 1 and 5 --> ";
			}

			cin >> optionSelected;
		}

		switch (optionSelected)
		{
		case AddItem:
			addItem(itemCount, AllItems);
			break;

		case RemoveItem:
			removeItem(itemCount, AllItems);
			break;

		case ModifyItem:
			break;

		case PrintContents:
			printItems(itemCount, AllItems);
			break;

		default:
			cout << "\nClosing program...";
		}

	} while (optionSelected != 5);
	return 0;
}

void removeItem(int& itemCount, std::unique_ptr<Inventory[]>& AllItems)
{
	cout << "\n\t- Which ITEM do you wish to remove? --> ";
	int itemNumber{};
	cin >> itemNumber;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\nSorry, enter a valid option --> ";
		cin >> itemNumber;
	}

	for (size_t i{}; i < itemCount; i++)
	{
		if (AllItems[i].getItemNumber() == itemNumber)
		{
			cout << "\nItem found!"
				<< "\nRemoving...";

			unique_ptr<Inventory[]> AllItems2(new Inventory[--itemCount]);

			for (size_t j{}; j < itemCount; j++)
			{
				if (j == i)
				{
					continue;
				}
				else
				{
					AllItems2[j].setItemNumber(AllItems[j].getItemNumber()).setQuantity(AllItems[j].getQuantity()).setCost(AllItems[j].getCost()).setTotalCost(AllItems[j].getTotalCost());
				}
			}

			AllItems = move(AllItems2);
		}
		else
		{
			cout << "\nThe item was not found!"
				<< "\nTry searching again...";
		}
	}
}

void printItems(int itemCount, std::unique_ptr<Inventory[]>& AllItems)
{
	if (itemCount == 0)
	{
		cout << "\nThere are no items!";
	}
	else
	{
		for (size_t i{}; i < itemCount; i++)
		{
			cout << "\nItem #" << (i + 1)
				<< "\n\t- Item ID --> " << AllItems[i].getItemNumber()
				<< "\n\t- Item Quantity --> " << AllItems[i].getQuantity()
				<< "\n\t- Item Cost --> $" << AllItems[i].getCost()
				<< "\n\t- Total Cost for this Item --> $" << AllItems[i].getTotalCost();
		}
	}
}

void addItem(int& itemCount, std::unique_ptr<Inventory[]>& AllItems)
{
	unique_ptr<Inventory[]> AllItems2(new Inventory[++itemCount]);
	for (size_t i{}; i < (itemCount - 1); i++)
	{
		AllItems2[i].setItemNumber(AllItems[i].getItemNumber()).setQuantity(AllItems[i].getQuantity()).setCost(AllItems[i].getCost()).setTotalCost(AllItems[i].getTotalCost());
	}

	AllItems = move(AllItems2);

	cout << "\nItem #" << itemCount
		<< "\n\t- Enter the ITEM NUMBER --> ";
	int itemNumber{};
	cin >> itemNumber;
	inputValidation(itemNumber);

	cout << "\t- Enter the ITEM QUANTITY --> ";
	int itemQuantity{};
	cin >> itemQuantity;
	inputValidation(itemQuantity);

	cout << "\t- Enter the ITEM COST --> $";
	double itemCost{};
	cin >> itemCost;
	inputValidation2(itemCost);

	AllItems[(itemCount - 1)].setItemNumber(itemNumber).setQuantity(itemQuantity).setCost(itemCost);
}

void inputValidation2(double& inputValue)
{
	while (cin.fail() || inputValue < 0.0)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\nInvalid entry, re-enter a valid value --> ";
		}
		else if (inputValue < 1)
		{
			cout << "\nNo negative values accepted, re-enter --> ";
		}

		cin >> inputValue;
	}
}

void inputValidation(int& inputValue)
{
	while (cin.fail() || inputValue < 1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\nInvalid entry, re-enter a valid value --> ";
		}
		else if (inputValue < 1)
		{
			cout << "\nNo negative values accepted, re-enter --> ";
		}

		cin >> inputValue;
	}
}