#include "Item.h"

Item::Item() {
    itemName = "";
    itemType = "";
    itemValue = 0;
    inBundle = false;
}

Item::Item(string n, string t, int v, bool b) {
    itemName = n;
    itemType = t;
    itemValue = v;
    inBundle = b;
}

string Item::getName() {
    return itemName;
}

string Item::getType() {
    return itemType;
}

int Item::getValue() {
    return itemValue;
}

bool Item::isBundleItem() {
    return inBundle;

void Item::displayItem() {
    cout << "Item name: " << itemName << endl << "Item type: " << itemType << endl << "Item value: " << itemValue << endl << "In bundle: " << inBundle << endl;
}
}