#include "RestaurantMenu.h"

RestaurantMenu::RestaurantMenu(MyString* sourceMenuNames, const double* sourceMenuPrices, const size_t sourceMenuSize) : menuSize(sourceMenuSize)
{
	if (sourceMenuNames == nullptr && sourceMenuPrices == nullptr) {
		this->menuNames = nullptr;
		this->menuPrices = nullptr;
	}
	else {
		this->menuNames = new MyString[getMenuSize()]{};
		this->menuPrices = new double[getMenuSize()] {};

		for (size_t i{}; i < getMenuSize(); i++) {
			this->menuNames[i] = sourceMenuNames[i];
			this->menuPrices[i] = sourceMenuPrices[i];
		}

		sourceMenuNames = nullptr;
		sourceMenuPrices = nullptr;
	}
}

RestaurantMenu::RestaurantMenu(const RestaurantMenu& sourceMenu) : menuSize(sourceMenu.getMenuSize())
{
	if (sourceMenu.getMenuNames() == nullptr && sourceMenu.getMenuPrices() == nullptr) {
		this->menuNames = nullptr;
		this->menuPrices = nullptr;
	}
	else {
		this->menuNames = new MyString[getMenuSize()]{};
		this->menuPrices = new double[getMenuSize()] {};

		for (size_t i{}; i < getMenuSize(); i++) {
			this->menuNames[i] = sourceMenu.menuNames[i];
			this->menuPrices[i] = sourceMenu.menuPrices[i];
		}
	}
}

RestaurantMenu::RestaurantMenu(RestaurantMenu&& sourceMenu) noexcept :
	menuNames(sourceMenu.getMenuNames()),
	menuPrices(sourceMenu.getMenuPrices()),
	menuSize(sourceMenu.getMenuSize())
{
	sourceMenu.menuNames = nullptr;
	sourceMenu.menuPrices = nullptr;
	sourceMenu.menuSize = 0;
}

RestaurantMenu& RestaurantMenu::operator=(const RestaurantMenu& sourceMenu)
{
	if (this != &sourceMenu) {
		if (getMenuNames() != nullptr && getMenuPrices() != nullptr) {
			delete[] this->menuNames;
			delete[] this->menuPrices;
		}

		if (sourceMenu.getMenuNames() == nullptr && sourceMenu.getMenuPrices() == nullptr) {
			this->menuNames = nullptr;
			this->menuPrices = nullptr;
		}
		else {
			this->menuSize = sourceMenu.getMenuSize();
			this->menuNames = new MyString[getMenuSize()];
			this->menuPrices = new double[getMenuSize()];

			for (size_t i{}; i < getMenuSize(); i++) {
				this->menuNames[i] = sourceMenu.menuNames[i];
				this->menuPrices[i] = sourceMenu.menuPrices[i];
			}
		}
	}

	return *this;
}

RestaurantMenu& RestaurantMenu::operator=(RestaurantMenu&& sourceMenu) noexcept
{
	if (this != &sourceMenu) {
		if (this->getMenuNames() && this->getMenuPrices() != nullptr) {
			delete[] this->getMenuNames();
			delete[] this->getMenuPrices();
		}

		if (sourceMenu.getMenuNames() == nullptr && sourceMenu.getMenuPrices() == nullptr) {
			this->menuNames = nullptr;
			this->menuPrices = nullptr;
		}
		else {
			this->menuNames = sourceMenu.getMenuNames();
			this->menuPrices = sourceMenu.getMenuPrices();
			this->menuSize = sourceMenu.getMenuSize();
		}
	}

	return *this;
}

MyString& RestaurantMenu::operator[](const int& index)
{
	if (index < 0 || index > this->getMenuSize()) {
		throw exception("Array bounds exceeded...");
	}

	return this->menuNames[index];
}

const size_t RestaurantMenu::getMenuSize() const
{
	return menuSize;
}

const double RestaurantMenu::getTax() const
{
	return stateTax;
}

MyString* RestaurantMenu::getMenuNames() const
{
	return menuNames;
}

double* RestaurantMenu::getMenuPrices() const
{
	return menuPrices;
}

RestaurantMenu::~RestaurantMenu()
{
	if (getMenuNames() != nullptr) {
		delete[] this->getMenuNames();
		this->menuNames = nullptr;
	}

	if (getMenuPrices() != nullptr) {
		delete[] this->getMenuPrices();
		this->menuPrices = nullptr;
	}
}

istream& operator>>(istream& input, RestaurantMenu& sourceMenu)
{
	cout << "\t- How many ITEMS do you want to record? --> ";
	input >> sourceMenu.menuSize;

	while (input.fail() || sourceMenu.getMenuSize() < 1) {
		if (input.fail()) {
			input.clear();
			input.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nRe-enter a valid amount of items to save in the menu --> ";
			input >> sourceMenu.menuSize;
		}
		else {
			cout << "\nRe-enter a valid amount of items above zero to save in the menu --> ";
			input >> sourceMenu.menuSize;
		}
	}

	if (sourceMenu.getMenuNames() != nullptr) {
		delete[] sourceMenu.getMenuNames();
	}

	if (sourceMenu.getMenuPrices() != nullptr) {
		delete[] sourceMenu.getMenuPrices();
	}

	sourceMenu.menuNames = new MyString[sourceMenu.getMenuSize()]{};
	sourceMenu.menuPrices = new double[sourceMenu.getMenuSize()] {};

	cout << '\n';
	for (size_t i{}; i < sourceMenu.getMenuSize(); i++) {
		cout << "\t- Enter ITEM #" << (i + 1) << " NAME --> ";
		input.ignore(numeric_limits<streamsize>::max(), '\n');
		input >> sourceMenu.menuNames[i];

		cout << "\t- Enter the " << sourceMenu.menuNames[i] << " PRICE --> $";
		input >> sourceMenu.menuPrices[i];

		while (input.fail() || sourceMenu.menuPrices[i] < 1) {
			if (input.fail()) {
				input.clear();
				input.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nRe-enter a valid PRICE for the item --> $";
				input >> sourceMenu.menuPrices[i];
			}
			else {
				cout << "\nRe-enter a valid price above negative numbers --> ";
				input >> sourceMenu.menuPrices[i];
			}
		}
		cout << '\n';
	}

	return input;
}

ostream& operator<<(ostream& output, const RestaurantMenu& sourceMenu)
{
	// Calculate the maximum width of the item name column
	size_t maxItemNameWidth{};
	for (size_t i{}; i < sourceMenu.getMenuSize(); i++) {
		if (sourceMenu.menuNames[i].getStrSize() > maxItemNameWidth) {
			maxItemNameWidth = sourceMenu.menuNames[i].getStrSize();
		}
	}

	// Output the menu with consistent alignment
	maxItemNameWidth += 10;
	output << "Items:" << setw(maxItemNameWidth + 4) << "Prices:\n";
	for (size_t i{}; i < sourceMenu.getMenuSize(); i++) {
		output << "- " << left << setw(maxItemNameWidth) << sourceMenu.menuNames[i] << "  $" << sourceMenu.menuPrices[i] << '\n';
	}

	return output;
}