#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
    protected:
    string name;
    string location;

    public:
    Character();
    Character(string n, string l);

    string getName();
    string getLocation();

};

#endif