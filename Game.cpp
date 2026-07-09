#include "Villager.h"
#include "Game.h"
#include <string>
#include<vector>
using namespace std;

Game::Game() {

}
Game(vector<Villager> v, Farmer p, boolgO) {
    villagers = v;
}

void loadCharacters() {
    ifstream inFile("characters.txt");
    if(inFile.is_open()) {
        string line;
        while(getline(inFile, line)) {
            int delimiter = line.find(',');
            string charName = line.substr(0, delimiter + 1);
            string charLocation = line.substr(delimiter, line.length() - charName.length() - 1);
        }
    }
}

void add bundle

void disolayMenu(){
    Cout //all menu options
}
int procedssChoice(int c) {
    if(c == 1 {
        //do
    }
    else if(c==2)
    //do
}
void handleRun();
void run(){
    //COUT welcome, rules, instructions, 
    while(choice != 3) || gameOver != true) {
        displayMenu();
        int input
        cin
        processChoice(input);
    }
}

};
