# csci1300_project
CSCI1300 final project by Kevin Tompkins

## Theme

Suggested Stardew Valley theme.

## Goal

Complete the final Community Center bundle before the season ends.

## How to compile and run

g++ -Wall -Werror -Wpedantic main.cpp Game.cpp Player.cpp Item.cpp Character.cpp -o game

## How to play

Every turn you can move around, search locations, talk to characters, view inventory, donate bundle items, visit JojaMart, or end the day. You have limited days and limited energy. Searching costs energy. JojaMart can help the player, but using Joja shortcuts increases Joja Influence and changes the ending.


## Classes

Item stores item information like name, type, value, and if it is needed for the bundle.

Player stores the farmer's name, day, energy, money, current location, and inventory. Item objects are stored in a vector.

Character stores a villager's name, location, dialogue, and reward item.

Game controls the game loop, map, menu, characters, bundle progress, Joja Influence, and ending.

## Extra credit

(TBA — or write "None")
