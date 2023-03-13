#pragma once

#include "RestaurantMenu.h"

class TableOrders
{
private: 
	MyString* checkNames;
	double* totalPerCheck;
	size_t checksCount;

public:
	TableOrders(const MyString* sourceCheckNames = nullptr, const double* totalPerCheck = nullptr, const size_t sourceCheckCount = 0);
	TableOrders(const TableOrders&);
	TableOrders(TableOrders&&) noexcept;

	TableOrders& operator = (const TableOrders&);
	TableOrders& operator = (TableOrders&&) noexcept;

	MyString& operator [] (const int&);

	friend istream& operator >> (istream&, TableOrders&);
	friend ostream& operator << (ostream&, const TableOrders&);

	const size_t getChecksCount() const;
	MyString* getCheckNames() const;
	double* getTotalPerCheck() const;

	~TableOrders();
};