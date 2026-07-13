#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "Item.h"

using namespace std;

class Character {
private:
    string name;
    string location;
    string dialogue;
    Item reward;
    bool rewardGiven;

public:
    Character();
    Character(string characterName, string characterLocation, string characterDialogue, Item rewardItem);

    string getName();
    string getLocation();
    bool hasRewardLeft();
    Item giveReward();
    void talk();
};

#endif
