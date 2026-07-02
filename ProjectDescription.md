# CSCI 1300 Final Project

# Project Description

## Theme

My game is a simple text-based farming adventure inspired by Stardew Valley. The player is a farmer trying to complete the final Community Center bundle before the season ends.

## Planned Classes

### Player
Stores the player name, current day, energy, money, current location, inventory, and Joja Influence.

### Item
Stores an item name, item type, value, and whether the item is needed for the bundle.

### Character
Stores a character name, location, friendship level, quest item, and reward item.

### Location
Stores a location name, description, available items, and characters at that location.

### Bundle
Tracks required items, donated items, and whether the final bundle is complete.

### Game
Controls the full game loop, menus, movement, inventory, bundle donations, JojaMart, and endings.

## Planned Limited Resource

The game will use time and energy as limited resources.

The player has 7 days to finish the final bundle. Each action costs energy. If the player runs out of energy the day ends.

## Plan for Handling Time

Each day the player will have a limited number of actions. After the player chooses to end the day, or runs out of energy, the current day increases by 1.

The game continues until the player completes the bundle or reaches the end of Day 7.

## Tradeoff System

My tradeoff system is JojaMart.

JojaMart lets the player buy food, restore energy, or buy missing bundle items. This helps the player finish faster, but each Joja purchase increases Joja Influence.

If Joja Influence gets too high, the ending becomes worse because JojaMart gains power in the town.

## Map Design

The game will use a simple connected-location text map.

                Mine
                  |
Forest --- Farm --- Town --- JojaMart
                  |
                 Lake
                  |
         Community Center

The player can move between locations using a menu. The current location will be displayed in the dashboard.

## Game Loop

Start game
Create player
Create items, characters, locations, and bundle

Repeat until win or loss:
    Display dashboard
    Show current day, energy, location, and bundle progress
    Ask player what they want to do
    Process player choice
    Update energy, inventory, or bundle progress
    Check win/loss condition

Display final ending

## Win/Lose Condition

### Win

The player wins by donating all required items to the Community Center before the end of Day 7.

### Lose

The player loses if Day 7 ends before the final bundle is complete.
