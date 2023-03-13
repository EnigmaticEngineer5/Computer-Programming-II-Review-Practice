#pragma once

#include "MyString.h"

#include <iomanip>

using std::exception;
using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;
using std::setw;
using std::left;

class RestaurantMenu
{
private:
	static constexpr const double stateTax = .105;
	MyString* menuNames;
	double* menuPrices;
	size_t menuSize;

public:
	RestaurantMenu(MyString* sourceMenuNames = nullptr, const double* sourceMenuPrices = nullptr, const size_t sourceMenuSize = 0);
	RestaurantMenu(const RestaurantMenu&);
	RestaurantMenu(RestaurantMenu&&) noexcept;

	RestaurantMenu& operator = (const RestaurantMenu&);
	RestaurantMenu& operator = (RestaurantMenu&&) noexcept;

	MyString& operator [] (const int&);

	friend istream& operator >> (istream&, RestaurantMenu&);
	friend ostream& operator << (ostream&, const RestaurantMenu&);

	const size_t getMenuSize() const;
	const double getTax() const;
	MyString* getMenuNames() const;
	double* getMenuPrices() const;

	~RestaurantMenu();
};