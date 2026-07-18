# CSCI 1300 Final Project

# Project Description

## Theme

My game is a simple text-based bundle game inspired by Stardew Valley. The player is a farmer trying to complete the final Community Center bundle before the season ends.

## Current Classes

### Player

Stores the player name, current day, maximum days, energy, maximum energy, money, current location, and inventory. The inventory stores `Item` objects. The Player class can add items, remove items, check for items, spend energy, spend money, restore energy, move to the next day, and display the inventory.

### Item

Stores an item name, item type, value, and whether the item is needed for the final bundle.

### Character

Stores a character name, location, dialogue, optional reward item, whether the character has a reward, and whether that reward has already been given. Some characters give items and some characters only provide dialogue.

### Game

Controls the full game loop, menus, movement, location searching, character interactions, inventory viewing, bundle donations, JojaMart, saving/loading, and endings. The Game class stores the player, the list of characters, the list of locations, the needed bundle items, donated bundle items, Joja Influence, and game state.

## Limited Resources

The game uses time, energy, and money as limited resources.

The player has 7 days to finish the final bundle. Searching locations and moving between locations cost energy. JojaMart purchases cost money. Ending the day restores energy but moves the player closer to the season deadline.

## Time System

The player starts on Day 1 and has until the end of Day 7 to complete the final bundle. The player can choose to end the day from the menu. When a new day starts, the player’s energy is restored. The game continues until the player completes the final bundle, quits, or runs out of days.

## Tradeoff System

The tradeoff system is JojaMart. JojaMart lets the player buy bundle items or restore energy. This can help the player finish the bundle, but each Joja purchase increases Joja Influence. Joja Influence affects the ending. If the player completes the bundle without using JojaMart, they get a better ending. If they use JojaMart, they get a less good ending.

## Map Design

The game uses a simple connected-location text map.

        [Mines]
           |
[Farm] -- [Town] -- [Community Center] -- [Beach]
   |          |
[Forest]  [JojaMart]

The player can move between locations using a menu. The current location is displayed in the dashboard.

## Inventory System

The player has an inventory stored as a vector of Item objects. The player can collect items by searching locations, talking to characters, or buying from JojaMart. The player can view their inventory from the menu. Bundle items in the inventory can be donated.

## Final Bundle

The final bundle is made of these items:

- Parsnip
- Sunfish
- Copper Ore
- Egg
- Wild Horseradish

The dashboard shows the player’s bundle progress. The Community Center menu shows which items have already been donated.

## Characters

The game includes several characters located around town. Characters can give hints or bundle items.

## Save and Load System

The game includes a save and load system using file input/output. The save file stores important game information such as the current day, energy, money, location, inventory items, donated bundle items, and Joja Influence.

Loading a game replaces the current game variables with the saved game variables.

## Game Loop

Start game  
Create player  
Create items, characters, locations, and bundle  

Repeat until win or loss:

Display dashboard  
Show current day, energy, money, location, Joja Influence, map, and bundle progress  
Ask player what they want to do  
Process player choice  
Update energy, money, inventory, location, or bundle progress  
Check win/loss condition  

Display final ending.

## Win/Lose Condition

### Win

The player wins by donating all required items to the Community Center before the end of Day 7.

### Lose

The player loses if the season ends before the final bundle is complete.

## Possible Endings

If the player completes the bundle without using JojaMart, the Community Center is restored through community effort.

If the player completes the bundle after using JojaMart, the bundle is complete, but JojaMart has gained influence in town.

If the player runs out of days, the season ends before the final bundle is complete.