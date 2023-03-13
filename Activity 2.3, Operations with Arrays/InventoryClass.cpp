#include "InventoryClass.h"

Inventory::Inventory(const int sourceItemNumber, const int sourceQuantity, const double sourceCost, const double sourceTotalCost) :
	itemNumber{ make_unique<int>(sourceItemNumber) },
	quantity{ make_unique<int>(sourceQuantity) },
	cost{ make_unique<double>(sourceCost) },
	totalCost{ make_unique<double>(sourceTotalCost) }
{
	cout << "\nConstructor invoked...";
}

Inventory& Inventory::setItemNumber(const int sourceItemNumber)
{
	if (itemNumber != nullptr)
	{
		itemNumber.reset();
		this->itemNumber = make_unique<int>(sourceItemNumber);
	}
	else
	{
		this->itemNumber = make_unique<int>(sourceItemNumber);
	}

	return *this;
}

Inventory& Inventory::setQuantity(const int sourceQuantity)
{
	if (quantity != nullptr)
	{
		quantity.reset();
		this->quantity = make_unique<int>(sourceQuantity);
	}
	else
	{
		this->quantity = make_unique<int>(sourceQuantity);
	}

	return *this;
}

Inventory& Inventory::setCost(const double sourceCost)
{
	if (cost != nullptr)
	{
		cost.reset();
		this->cost = make_unique<double>(sourceCost);
	}
	else
	{
		this->cost = make_unique<double>(sourceCost);
	}

	return *this;
}

Inventory& Inventory::setTotalCost(const double sourceTotalCost)
{
	if (totalCost != nullptr)
	{
		totalCost.reset();
		this->totalCost = make_unique<double>(sourceTotalCost);
	}
	else
	{
		this->totalCost = make_unique<double>(sourceTotalCost);
	}

	return *this;
}

const int Inventory::getItemNumber() const
{
	return *itemNumber;
}

const int Inventory::getQuantity() const
{
	return *quantity;
}

const double Inventory::getCost() const
{
	return *cost;
}

const double Inventory::getTotalCost() const
{
	*totalCost = (*cost * *quantity);
	return *totalCost;
}

Inventory::~Inventory()
{
	cout << "\nDestructor invoked...\n";
}