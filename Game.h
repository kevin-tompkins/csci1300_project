#ifndef CHARACTER_H
#define CHARACTER_H

#include "Villager.h"
#include <string>
#include<vector>
using namespace std;

class Game {
    private:
vector<Villager> villagers;
Farmer player;
bool gameOver;

public:
Game();
Game(vector<Villager> v, Farmer p, boolgO);

void loadCharacteristics();
void disolayMenu();
int procedssChoice(int c);
void handleRun();
void run();

};

#endif