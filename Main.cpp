#include <iostream>
#include <string>

#include "Game.h"

using namespace std;

int main() {
    string name;

    cout << "Welcome to The Final Bundle!" << endl;
    cout << "Enter your farmer name: ";
    cin >> name;

    Game game(name);
    game.run();

    return 0;
}
