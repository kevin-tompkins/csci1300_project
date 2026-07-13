#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    string name;
    string type;
    int value;
    bool bundleItem;

public:
    Item();
    Item(string itemName, string itemType, int itemValue, bool neededForBundle);

    string getName();
    string getType();
    int getValue();
    bool isBundleItem();

    void displayItem();
};

#endif
