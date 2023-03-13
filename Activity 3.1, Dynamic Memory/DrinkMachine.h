#pragma once

#include <iostream>

using std::cout;
using std::cin;

class DrinkMachine
{
private:
	char* drinkName;
	double* drinkPrice;
	int drinkQuantity;

public:
	DrinkMachine(char* drinkName = nullptr, double* drinkPrice = nullptr, int drinkQuantity = 0);
	DrinkMachine(DrinkMachine&&) noexcept;

	DrinkMachine& setDrinkName(const char*);
	DrinkMachine& setDrinkPrice(const double*);
	DrinkMachine& setDrinkQuantity(const int);

	char* getDrinkName() const;
	double* getDrinkPrice() const;
	int getDrinkQuantity() const;

	~DrinkMachine();
};