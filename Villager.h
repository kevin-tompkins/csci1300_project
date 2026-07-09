#ifndef VILLAGER_H
#define VILLAGER_H

#include "Character.h"
#include <string>
using namespace std;

class Villager : public Character {
    protected:
    int friendship;

    public:
    Villager();
    Villager(string)

};

#endif