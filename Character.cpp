#include "Character.h"

#include <iostream>

using namespace std;
// Set the default variable values for character
Character::Character() {
    name = "Unknown";
    location = "Town";
    dialogue = "Hello.";
    reward = Item();
    rewardGiven = true;
}
// Constructor for a character so you can create a character with the given inputs as variable values
Character::Character(string characterName, string characterLocation, string characterDialogue, Item rewardItem, bool hasReward) {
    name = characterName;
    location = characterLocation;
    dialogue = characterDialogue;
    reward = rewardItem;
    rewardGiven = !hasReward;
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
// Prints double quotes around the dialogue variable.
void Character::talk() {
    cout << name << " says:" << endl;
    cout << "\"" << dialogue << "\"" << endl;
}
