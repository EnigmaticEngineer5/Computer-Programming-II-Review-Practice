void buyDrink(double& drinkPayment, double& total, DrinkMachine* allDrinks[5], int optionSelected);
void doubleValuesValidation(double& drinkPayment);
void adjustQuantity(DrinkMachine* allDrinks[5], int optionSelected);
void checkStock(DrinkMachine* allDrinks[5], int& optionSelected, double& drinkPayment, double& total);
void wipeHeapMemory(double*& drinkPrice1, double*& drinkPrice2, char*& drinkName1, char*& drinkName2, char*& drinkName3, char*& drinkName4, char*& drinkName5);
void chooseDrink(DrinkMachine* allDrinks[5], int& optionSelected);
void defaultDrinks(char* drinkName1, char* drinkName2, char* drinkName3, char* drinkName4, char* drinkName5);