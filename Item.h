#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    string itemName;
    string itemType;
    int itemValue;
    bool inBundle;

public:
    Item();
    Item(string itemName, string itemType, int itemValue, bool inBundle);

    string getName();
    string getType();
    int getValue();
    bool isBundleItem();

    void displayItem();
};

#endif
