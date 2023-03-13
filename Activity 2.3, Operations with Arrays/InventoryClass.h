#pragma once

#include <iostream>
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::cout;
using std::cin;
using std::move;

class Inventory
{
private:
	unique_ptr<int> itemNumber = nullptr, quantity = nullptr;
	unique_ptr<double> cost = nullptr, totalCost = nullptr;

public:
	Inventory(const int sourceItemNumber = 0, const int sourceQuantity = 0, const double sourceCost = 0.0, const double sourceTotalCost = 0.0);

	Inventory& setItemNumber(const int sourceItemNumber);
	Inventory& setQuantity(const int sourceQuantity);
	Inventory& setCost(const double sourceCost);
	Inventory& setTotalCost(const double sourceTotalCost);

	const int getItemNumber() const;
	const int getQuantity() const;
	const double getCost() const;
	const double getTotalCost() const;

	~Inventory();
};