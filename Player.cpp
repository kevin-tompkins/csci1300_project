#include "Player.h"

#include <iostream>

using namespace std;
//Default variable values for Player class
Player::Player() {
    name = "Farmer";
    location = "Farm";
    day = 1;
    maxDays = 7;
    energy = 10;
    maxEnergy = 10;
    money = 50;
}
//Lets you create a Player with chosen playerName 
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
// Returns the number of Objects in the inventory vector as an integer
int Player::getInventorySize() {
    return static_cast<int>(inventory.size());
}
// Changes the location variable of a Player
void Player::setLocation(string newLocation) {
    location = newLocation;
}
// Add an item to the inventory vector
void Player::addItem(Item item) {
    inventory.push_back(item);
}
// Looks through each index of the inventory vector and returns true if the name of one of the items equals the given item name and returns false otherwise
bool Player::hasItem(string itemName) {
    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        if (inventory[i].getName() == itemName) {
            return true;
        }
    }

    return false;
}
// Looks through each index of the inventory vector and if the name of an object matches the given item name then it removes that object from the inventory vector. Then, inventory.begin() + i shifts every element after index i one position left to fill the gap, reducing the vectors size by one. Otherwise, returns false.
bool Player::removeItem(string itemName) {
    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        if (inventory[i].getName() == itemName) {
            inventory.erase(inventory.begin() + i);
            return true;
        }
    }

    return false;
}
// If energy is less than the given amount return false. Otherwise, subtract the given amount from the energy variable.
bool Player::spendEnergy(int amount) {
    if (energy < amount) {
        return false;
    }

    energy -= amount;
    return true;
}
// If money is less than the given amount return false. Otherwise, subtract the given amount from the money variable
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
// Prints given text and prints empty if the inventory vector has zero elements and otherwise goes through each element of the inventory vector and prints that elements corresponding text specified in the displayItem() function.
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

void Player::setDay(int newDay) {
    day = newDay;
}

void Player::setEnergy(int newEnergy) {
    energy = newEnergy;
}

void Player::setMoney(int newMoney) {
    money = newMoney;
}

Item Player::getInventoryItem(int index) {
    return inventory[index];
}

void Player::clearInventory() {
    inventory.clear();
}
