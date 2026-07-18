#include "Item.h"

#include <iostream>

using namespace std;
//Sets default values for variables in the Item class
Item::Item() {
    name = "None";
    type = "None";
    value = 0;
    bundleItem = false;
}
//Constructor allows you to create Items with certain variable values
Item::Item(string itemName, string itemType, int itemValue, bool neededForBundle) {
    name = itemName;
    type = itemType;
    value = itemValue;
    bundleItem = neededForBundle;
}

string Item::getName() {
    return name;
}

string Item::getType() {
    return type;
}

int Item::getValue() {
    return value;
}

bool Item::isBundleItem() {
    return bundleItem;
}

void Item::displayItem() {
    cout << name << " - " << type << " (" << value << "g)";
}
