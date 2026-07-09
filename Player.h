#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Item.h"

using namespace std;

class Player {
private:
    string name;
    string location;
    int day;
    int maxDays;
    int energy;
    int maxEnergy;
    int money;
    vector<Item> inventory;

public:
    Player();
    Player(string playerName);

    string getName();
    string getLocation();
    int getDay();
    int getMaxDays();
    int getEnergy();
    int getMoney();
    int getInventorySize();

    void setLocation(string newLocation);
    void addItem(Item item);
    bool hasItem(string itemName);
    bool removeItem(string itemName);
    bool spendEnergy(int amount);
    bool spendMoney(int amount);
    void addMoney(int amount);
    void restoreEnergy();
    void nextDay();
    void displayInventory();
};

#endif
