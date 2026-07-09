#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Character.h"
using namespace std;

Character::Character() {
    name = "Default";
    location = "Farm";
}
    string getName();
    string getLocation();
    void setName();
    void setLocation();

#endif