#include "DrinkMachine.h"

DrinkMachine::DrinkMachine(char* sourceDrinkName, double* sourceDrinkPrice, int sourceDrinkQuantity) : drinkName{ sourceDrinkName }, drinkPrice{ sourceDrinkPrice }, drinkQuantity{ sourceDrinkQuantity }
{
	cout << "Default constructor invoked...\n";
}

DrinkMachine::DrinkMachine(DrinkMachine&& tmpSourceObject) noexcept : 
	drinkName{ std::exchange(tmpSourceObject.drinkName, nullptr) }, 
	drinkQuantity{ tmpSourceObject.getDrinkQuantity() }, 
	drinkPrice{ std::exchange(tmpSourceObject.drinkPrice, nullptr) }
{
	cout << "\nMove constructor invoked...";
}

DrinkMachine& DrinkMachine::setDrinkName(const char* sourceDrinkName)
{
	const size_t nameLength = strlen(sourceDrinkName);
	this->drinkName = new char[nameLength + 1];
	strncpy_s(this->drinkName, nameLength + 1, sourceDrinkName, nameLength);
	return *this;
}

DrinkMachine& DrinkMachine::setDrinkPrice(const double* sourceDrinkPrice)
{
	this->drinkPrice = new double;
	*drinkPrice = *sourceDrinkPrice;

	return *this;
}

DrinkMachine& DrinkMachine::setDrinkQuantity(const int  sourceDrinkQuantity)
{
	this->drinkQuantity = sourceDrinkQuantity;
	return *this;
}

char* DrinkMachine::getDrinkName() const
{
	return drinkName;
}

double* DrinkMachine::getDrinkPrice() const
{
	return drinkPrice;
}

int DrinkMachine::getDrinkQuantity() const
{
	return drinkQuantity;
}

DrinkMachine::~DrinkMachine()
{
	cout << "\nDestructor invoked...";

	if (drinkName != nullptr)
	{
		delete[] drinkName;
		drinkName = nullptr;
	}

	if (drinkPrice != nullptr)
	{
		delete drinkPrice;
		drinkPrice = nullptr;
	}
}