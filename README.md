# csci1300_project
CSCI1300 final project by Kevin Tompkins

## Theme

Suggested Stardew Valley theme.

## Goal

Complete the final Community Center bundle before the week ends.

## How to compile and run

g++ -Wall -Werror -Wpedantic main.cpp Game.cpp Player.cpp Item.cpp Character.cpp -o game

## How to play

Every turn you can move around, search locations, talk to characters, view inventory, donate bundle items, visit JojaMart, end the day, save game, or load game. You have limited days and limited energy. Searching and moving costs 2 energy. JojaMart can help the player, but using Joja shortcuts increases Joja Influence and changes the ending.


## Classes

Item stores item information like name, type, value, and if it is needed for the bundle.

Player stores the farmer's name, day, energy, money, current location, and inventory. Item objects are stored in a vector.

Character stores a villager's name, location, dialogue, and reward item.

Game keeps track of the player, characters, locations, bundle progress, Joja influence, and the game’s win/loss status. Game also contains functions like displaying the dashboard, moving the player, searching locations, talking to characters, donating items, saving, loading, and running the main game loop.

## Extra credit

File input/output, allowing the player to save their place and then load back in with the same variables.