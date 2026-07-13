#include "Character.h"

#include <iostream>

using namespace std;

Character::Character() {
    name = "Unknown";
    location = "Town";
    dialogue = "Hello.";
    reward = Item();
    rewardGiven = true;
}

Character::Character(string characterName, string characterLocation, string characterDialogue, Item rewardItem) {
    name = characterName;
    location = characterLocation;
    dialogue = characterDialogue;
    reward = rewardItem;
    rewardGiven = false;
}

string Character::getName() {
    return name;
}

string Character::getLocation() {
    return location;
}

bool Character::hasRewardLeft() {
    return !rewardGiven;
}

Item Character::giveReward() {
    rewardGiven = true;
    return reward;
}

void Character::talk() {
    cout << name << " says:" << endl;
    cout << "\"" << dialogue << "\"" << endl;
}
