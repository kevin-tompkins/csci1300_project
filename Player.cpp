#include "Player.h"

#include <iostream>

using namespace std;

Player::Player() {
    name = "Farmer";
    location = "Farm";
    day = 1;
    maxDays = 7;
    energy = 10;
    maxEnergy = 10;
    money = 50;
}

Player::Player(string playerName) {
    name = playerName;
    location = "Farm";
    day = 1;
    maxDays = 7;
    energy = 10;
    maxEnergy = 10;
    money = 50;
}

string Player::getName() {
    return name;
}

string Player::getLocation() {
    return location;
}

int Player::getDay() {
    return day;
}

int Player::getMaxDays() {
    return maxDays;
}

int Player::getEnergy() {
    return energy;
}

int Player::getMoney() {
    return money;
}

int Player::getInventorySize() {
    return static_cast<int>(inventory.size());
}

void Player::setLocation(string newLocation) {
    location = newLocation;
}

void Player::addItem(Item item) {
    inventory.push_back(item);
}

bool Player::hasItem(string itemName) {
    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        if (inventory[i].getName() == itemName) {
            return true;
        }
    }

    return false;
}

bool Player::removeItem(string itemName) {
    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        if (inventory[i].getName() == itemName) {
            inventory.erase(inventory.begin() + i);
            return true;
        }
    }

    return false;
}

bool Player::spendEnergy(int amount) {
    if (energy < amount) {
        return false;
    }

    energy -= amount;
    return true;
}

bool Player::spendMoney(int amount) {
    if (money < amount) {
        return false;
    }

    money -= amount;
    return true;
}

void Player::addMoney(int amount) {
    money += amount;
}

void Player::restoreEnergy() {
    energy = maxEnergy;
}

void Player::nextDay() {
    day++;
    restoreEnergy();
}

void Player::displayInventory() {
    cout << "Inventory:" << endl;

    if (inventory.size() == 0) {
        cout << "- Empty" << endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        cout << i + 1 << ". ";
        inventory[i].displayItem();
        cout << endl;
    }
}
