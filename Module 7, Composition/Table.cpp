#include "Table.h"

TableOrders::TableOrders(const MyString* sourceCheckNames, const double* totalPerCheck, const size_t sourceCheckCount) : checksCount(sourceCheckCount)
{
    if (sourceCheckNames == nullptr && totalPerCheck == nullptr) {
        this->checkNames = nullptr;
        this->totalPerCheck = nullptr;
    }
    else {
        this->checkNames = new MyString[getChecksCount()]{};
        this->totalPerCheck = new double[getChecksCount()] {};

        for (size_t i{}; i < getChecksCount(); i++) {
            this->checkNames[i] = sourceCheckNames[i];
            this->totalPerCheck[i] = totalPerCheck[i];
        }

        sourceCheckNames = nullptr;
        totalPerCheck = nullptr;
    }
}

TableOrders::TableOrders(const TableOrders& sourceTable) : checksCount{ sourceTable.getChecksCount() }
{
    if (sourceTable.getCheckNames() == nullptr && sourceTable.getTotalPerCheck() == nullptr) {
        this->checkNames = nullptr;
        this->totalPerCheck = nullptr;
    }
    else {
        this->checkNames = new MyString[getChecksCount()]{};
        this->totalPerCheck = new double[getChecksCount()] {};

        for (size_t i{}; i < getChecksCount(); i++) {
            this->checkNames[i] = sourceTable.checkNames[i];
            this->totalPerCheck[i] = sourceTable.totalPerCheck[i];
        }
    }
}

TableOrders::TableOrders(TableOrders&& sourceTable) noexcept :
    checkNames(sourceTable.getCheckNames()),
    totalPerCheck(sourceTable.getTotalPerCheck()),
    checksCount(sourceTable.getChecksCount())
{
    sourceTable.checkNames = nullptr;
    sourceTable.totalPerCheck = nullptr;
    sourceTable.checksCount = 0;
}

TableOrders& TableOrders::operator=(const TableOrders& sourceTable)
{
    if (this != &sourceTable) {
        if (getCheckNames() != nullptr && getTotalPerCheck() == nullptr) {
            delete[] this->checkNames;
            delete[] this->totalPerCheck;
        }

        if (sourceTable.getCheckNames() == nullptr && sourceTable.getTotalPerCheck() == nullptr) {
            this->checkNames = nullptr;
            this->totalPerCheck = nullptr;
        }
        else {
            this->checksCount = sourceTable.getChecksCount();
            this->checkNames = new MyString[getChecksCount()]{};
            this->totalPerCheck = new double[getChecksCount()] {};

            for (size_t i{}; i < getChecksCount(); i++)
            {
                this->checkNames[i] = sourceTable.checkNames[i];
                this->totalPerCheck[i] = sourceTable.totalPerCheck[i];
            }
        }
    }

    return *this;
}

TableOrders& TableOrders::operator=(TableOrders&& sourceTable) noexcept
{
    if (this != &sourceTable) {
        if (this->getCheckNames() != nullptr && this->getTotalPerCheck() != nullptr) {
            delete[] this->getCheckNames();
            delete[] this->getTotalPerCheck();
        }

        if (sourceTable.getCheckNames() == nullptr && sourceTable.getTotalPerCheck() == nullptr) {
            this->checkNames = nullptr;
            this->totalPerCheck = nullptr;
        }
        else {
            this->checkNames = sourceTable.getCheckNames();
            this->totalPerCheck = sourceTable.getTotalPerCheck();
            this->checksCount = sourceTable.getChecksCount();
        }
    }

    return *this;
}

MyString& TableOrders::operator[](const int& index)
{
    if (index < 0 || index > this->getChecksCount()) {
        throw exception("Array bounds exceeded...");
    }

    return checkNames[index];
}

const size_t TableOrders::getChecksCount() const
{
    return checksCount;
}

MyString* TableOrders::getCheckNames() const
{
    return checkNames;
}

double* TableOrders::getTotalPerCheck() const
{
    return totalPerCheck;
}

TableOrders::~TableOrders()
{
    if (this->getCheckNames() != nullptr) {
        delete[] this->getCheckNames();
        this->checkNames = nullptr;
    }

    if (this->getTotalPerCheck() != nullptr) {
        delete[] this->getTotalPerCheck();
        this->totalPerCheck = nullptr;
    }
}

istream& operator>>(istream& input, TableOrders& sourceTable)
{
    cout << "\nEnter how many CHECKS for this table please --> ";
    return input;
}

ostream& operator<<(ostream& output, const TableOrders& sourceTable)
{
    return output;
}
