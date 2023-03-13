#pragma once

void inputValidation(int& itemNumber);
void inputValidation2(double& itemCost);
void addItem(int& itemCount, std::unique_ptr<Inventory[]>& AllItems);
void printItems(int itemCount, std::unique_ptr<Inventory[]>& AllItems);
void removeItem(int& itemCount, std::unique_ptr<Inventory[]>& AllItems);
