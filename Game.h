#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <fstream>

#include "Character.h"
#include "Player.h"

using namespace std;

class Game {
private:
    Player player;
    vector<Character> characters;
    vector<string> locations;
    vector<string> bundleNeeds;
    vector<string> donatedItems;
    int jojaInfluence;
    bool gameOver;
    bool won;

    void setupGame();
    void displayDashboard();
    void displayMap();
    void displayCharacterNear();
    void displayBundle();
    void displayMenu();
    int getNumberChoice();
    void movePlayer();
    void searchLocation();
    void talkToCharacter();
    void visitCommunityCenter();
    void visitJojaMart();
    void endDay();
    bool bundleComplete();
    bool alreadyDonated(string itemName);
    void displayEnding();
    void saveGame();
    void loadGame();
    Item loadItemFromName(string itemName);

public:
    Game();
    Game(string playerName);
    void run();
};

#endif
