#include "Game.h"

#include <iostream>
#include <limits>

using namespace std;
// Set default variable values for game
Game::Game() {
    player = Player();
    jojaInfluence = 0;
    gameOver = false;
    won = false;
    setupGame();
}
// Takes an input string player name and then creates a class object where the variable player is a object of the class player with the variable and put player name.
Game::Game(string playerName) {
    player = Player(playerName);
    jojaInfluence = 0;
    gameOver = false;
    won = false;
    setupGame();
}
// Adds all locations to the location vector and adds all characters to the character vector
void Game::setupGame() {
    locations.push_back("Farm");
    locations.push_back("Town");
    locations.push_back("Community Center");
    locations.push_back("Beach");
    locations.push_back("Mines");
    locations.push_back("Forest");
    locations.push_back("JojaMart");

    bundleNeeds.push_back("Parsnip");
    bundleNeeds.push_back("Sunfish");
    bundleNeeds.push_back("Copper Ore");
    bundleNeeds.push_back("Egg");
    bundleNeeds.push_back("Wild Horseradish");

    characters.push_back(Character("Lewis", "Town",
        "The Community Center needs one final bundle. Here's something I found that might help.",
        Item("Egg", "Animal Product", 50, true), true));
    characters.push_back(Character("Willy", "Beach",
        "The sea is generous if you have energy to fish.",
        Item(), false));
    characters.push_back(Character("Clint", "Mines",
        "There might be a little copper left around.", 
        Item(), false));
    characters.push_back(Character("Linus", "Forest",
        "You never know what might be growing in the forest.",
        Item(), false));
}
// While game over is false, it runs the display dashboard and display menu function and then assigns the integer choice a value using the get number choice function, and then if the choice is one through 10 it runs a corresponding function or else it outputs Choose a valid option text. Also, if the bundle is complete it sets won and game over to true or if the players day goes over the number of Max days only game over becomes true, and then last it runs the function display ending.
void Game::run() {
    while (!gameOver) {
        int choice;

        displayDashboard();
        displayMenu();
        choice = getNumberChoice();

        if (choice == 1) {
            movePlayer();
        } else if (choice == 2) {
            searchLocation();
        } else if (choice == 3) {
            talkToCharacter();
        } else if (choice == 4) {
            player.displayInventory();
        } else if (choice == 5) {
            visitCommunityCenter();
        } else if (choice == 6) {
            visitJojaMart();
        } else if (choice == 7) {
            endDay();
        } else if (choice == 8) {
            gameOver = true;
        } else if (choice == 9) {
            saveGame();
        } else if (choice == 10) {
            loadGame();
        } else {
            cout << "Please choose a valid option." << endl;
        }

        if (bundleComplete()) {
            won = true;
            gameOver = true;
        }

        if (player.getDay() > player.getMaxDays()) {
            gameOver = true;
        }
    }

    displayEnding();
}
// Print text and get function outputs for the player and then runs display map and display character near 
void Game::displayDashboard() {
    cout << endl;
    cout << "==================================================" << endl;
    cout << "                 THE FINAL BUNDLE                 " << endl;
    cout << "==================================================" << endl;
    cout << "Farmer: " << player.getName() << endl;
    cout << "Day: " << player.getDay() << " / " << player.getMaxDays();
    cout << "    Energy: " << player.getEnergy() << " / 10";
    cout << "    Money: " << player.getMoney() << "g" << endl;
    cout << "Location: " << player.getLocation() << endl;
    cout << "Joja Influence: " << jojaInfluence << endl;
    cout << "Bundle Progress: " << static_cast<int>(donatedItems.size());
    cout << " / " << static_cast<int>(bundleNeeds.size()) << endl;
    displayMap();
    displayCharacterNear();
}

void Game::displayMap() {
    cout << endl;
    cout << "Map:" << endl;
    cout << "        [Mines]" << endl;
    cout << "           |" << endl;
    cout << "[Farm] -- [Town] -- [Community Center] -- [Beach]" << endl;
    cout << "   |          |" << endl;
    cout << "[Forest]  [JojaMart]" << endl;
    cout << endl << "Current Location: " << player.getLocation() << endl;
}

void Game::displayBundle() {
    cout << endl;
    cout << "Final Bundle:" << endl;

    for (int i = 0; i < static_cast<int>(bundleNeeds.size()); i++) {
        if (alreadyDonated(bundleNeeds[i])) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }

        cout << bundleNeeds[i] << endl;
    }
}

void Game::displayMenu() {
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Move to another location" << endl;
    cout << "2. Search this location" << endl;
    cout << "3. Talk to someone nearby" << endl;
    cout << "4. View inventory" << endl;
    cout << "5. Donate to the Final Bundle" << endl;
    cout << "6. Visit JojaMart" << endl;
    cout << "7. End day" << endl;
    cout << "8. Quit" << endl;
    cout << "9. Save Game" << endl;
    cout << "10. Load Game" << endl;
    cout << "Choice: ";
}
// This function keeps asking the user for a number until they type a valid one, ignoring any bad input and clearing the input buffer so the program doesn’t get confused.
int Game::getNumberChoice() {
    int choice;

    while (!(cin >> choice)) {
        cout << "Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}
// If player spend energy function returns false, then it prints you are too tired tired to travel. Otherwise, it sets the player's location correlated to their choice and prints  corresponding text, or it prints that location does not exist 
void Game::movePlayer() {
    int choice;
    int moveCost = 2;

    cout << endl;
    cout << "Where would you like to go?" << endl;
    for (int i = 0; i < static_cast<int>(locations.size()); i++) {
        cout << i + 1 << ". " << locations[i] << endl;
    }
    cout << "Choice: ";
    choice = getNumberChoice();

    if (choice >= 1 && choice <= static_cast<int>(locations.size())) {
        if (!player.spendEnergy(moveCost)) {
            cout << "You are too tired to travel. End the day to rest." << endl;
            return;
        }

        player.setLocation(locations[choice - 1]);
        cout << "You travel to " << player.getLocation() << "." << endl;
    } else {
        cout << "That location does not exist." << endl;
    }
}
// If players spend energy returns false it prints corresponding text. Otherwise, if location equals a certain string it adds that location's corresponding item to the player's inventory. Or, it outputs text saying you found nothing 
void Game::searchLocation() {
    string location = player.getLocation();

    if (!player.spendEnergy(2)) {
        cout << "You are too tired to search. End the day to rest." << endl;
        return;
    }

    if (location == "Farm") {
        player.addItem(Item("Parsnip", "Crop", 20, true));
        cout << "You harvested a Parsnip." << endl;
    } else if (location == "Beach") {
        player.addItem(Item("Sunfish", "Fish", 30, true));
        cout << "You caught a Sunfish." << endl;
    } else if (location == "Mines") {
        player.addItem(Item("Copper Ore", "Mineral", 15, true));
        cout << "You found Copper Ore." << endl;
    } else if (location == "Forest") {
        player.addItem(Item("Wild Horseradish", "Forage", 25, true));
        cout << "You found Wild Horseradish." << endl;
    } else {
        cout << "You searched, but did not find a bundle item here." << endl;
    }
}
// It goes through each index of the characters vector and if a character's location equals the player's location found someone is set to true and it prints corresponding text . If found someone is false then it prints corresponding text. 
void Game::displayCharacterNear() {
    bool foundSomeone = false;

    for (int i = 0; i < static_cast<int>(characters.size()); i++) {
        if (characters[i].getLocation() == player.getLocation()) {
            foundSomeone = true;
            cout << "Character nearby: " << characters[i].getName() << endl;
        }
    }

    if (!foundSomeone) {
        cout << "No one is nearby right now." << endl;
    }
}
// Goes through each index of the characters vector and if a character's location equals the player's location, found someone is set to true and then it runs the characters index talk function. Then, if the character's index has reward left function returns true, an item called reward equal to the characters give reward function is created, and then that reward item is added to the player's inventory and corresponding text is printed. If found someone is false, it prints corresponding text.
void Game::talkToCharacter() {
    bool foundSomeone = false;

    for (int i = 0; i < static_cast<int>(characters.size()); i++) {
        if (characters[i].getLocation() == player.getLocation()) {
            foundSomeone = true;
            characters[i].talk();

            if (characters[i].hasRewardLeft()) {
                Item reward = characters[i].giveReward();
                player.addItem(reward);
                cout << characters[i].getName() << " gave you ";
                cout << reward.getName() << "." << endl;
            }
        }
    }

    if (!foundSomeone) {
        cout << "No one is nearby right now." << endl;
    }
}
// Goes through the bundle needs a vector and if already donated returns false and player has item returns true then it removes the item from the player's inventory and adds the item to the donated items vector and prints the corresponding text. Note how if already donated is false the exclamation point in the loop converts it to true. If the loop never runs then it prints corresponding text. Either way the last thing it does is run display bundle.
void Game::visitCommunityCenter() {
    for (int i = 0; i < static_cast<int>(bundleNeeds.size()); i++) {
        if (!alreadyDonated(bundleNeeds[i]) && player.hasItem(bundleNeeds[i])) {
            player.removeItem(bundleNeeds[i]);
            donatedItems.push_back(bundleNeeds[i]);
            cout << "You donated " << bundleNeeds[i] << " to the bundle." << endl;
            displayBundle();
            return;
        }
    }

    cout << "You do not have any needed bundle items to donate right now." << endl;

    displayBundle();
}

void Game::visitJojaMart() {
    int choice;

    cout << endl;
    cout << "Morris says: Joja can help, for a price." << endl;
    cout << "1. Buy an Parsnip bundle item - 50g" << endl;
    cout << "2. Buy an Sunfish bundle item - 50g" << endl;
    cout << "3. Buy an Copper Ore bundle item - 50g" << endl;
    cout << "4. Buy an Egg bundle item - 50g" << endl;
    cout << "5. Buy an Wild Horseradish bundle item - 50g" << endl;
    cout << "6. Buy Joja Cola energy boost - 25g" << endl;
    cout << "7. Leave" << endl;
    cout << "Choice: ";
    choice = getNumberChoice();

    if (choice == 1) {
        if (player.spendMoney(50)) {
            player.addItem(Item("Parsnip", "Crop", 50, true));
            jojaInfluence++;
            cout << "You bought a Parsnip. Joja Influence increased." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
    }

    else if (choice == 2) {
        if (player.spendMoney(50)) {
            player.addItem(Item("Sunfish", "Fish", 50, true));
            jojaInfluence++;
            cout << "You bought a Sunfish. Joja Influence increased." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
    } 

    else if (choice == 3) {
        if (player.spendMoney(50)) {
            player.addItem(Item("Copper Ore", "Mineral", 50, true));
            jojaInfluence++;
            cout << "You bought a Copper Ore. Joja Influence increased." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
    }

    else if (choice == 4) {
        if (player.spendMoney(50)) {
            player.addItem(Item("Egg", "Animal Product", 50, true));
            jojaInfluence++;
            cout << "You bought a Egg. Joja Influence increased." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
    }

    else if (choice == 5) {
        if (player.spendMoney(50)) {
            player.addItem(Item("Wild Horseradish", "Forage", 50, true));
            jojaInfluence++;
            cout << "You bought a Wild Horseradish. Joja Influence increased." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
    }

    else if (choice == 6) {
        if (player.spendMoney(20)) {
            player.restoreEnergy();
            jojaInfluence++;
            cout << "Your energy was restored. Joja Influence increased." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
    } else {
        cout << "You leave JojaMart." << endl;
    }
}

void Game::endDay() {
    player.nextDay();
    cout << "You go to sleep and wake up with full energy." << endl;
}

bool Game::bundleComplete() {
    return donatedItems.size() == bundleNeeds.size();
}

bool Game::alreadyDonated(string itemName) {
    for (int i = 0; i < static_cast<int>(donatedItems.size()); i++) {
        if (donatedItems[i] == itemName) {
            return true;
        }
    }

    return false;
}

void Game::displayEnding() {
    cout << endl;
    cout << "==================== Ending ====================" << endl;

    if (won && jojaInfluence == 0) {
        cout << "You restored the Community Center through community effort!" << endl;
    } else if (won) {
        cout << "You completed the bundle, but Joja gained influence in town." << endl;
    } else {
        cout << "The season ended before the final bundle was complete." << endl;
    }
}
// Takes in a string item name and if the item name equals a corresponding string then it returns an item with corresponding inputs. Otherwise, it returns an item with item name unknown zero and false.
Item Game::loadItemFromName(string itemName) {
    if (itemName == "Parsnip") {
        return Item("Parsnip", "Crop", 50, true);
    } else if (itemName == "Sunfish") {
        return Item("Sunfish", "Fish", 50, true);
    } else if (itemName == "Copper Ore") {
        return Item("Copper Ore", "Mineral", 50, true);
    } else if (itemName == "Egg") {
        return Item("Egg", "Animal Product", 50, true);
    } else if (itemName == "Wild Horseradish") {
        return Item("Wild Horseradish", "Forage", 50, true);
    }

    return Item(itemName, "Unknown", 0, false);
}
// Create a file named save and opens it and then writes a series of functions into each line of the file. It does this in different ways and uses some loops later. Then it closes the file and prints game saved. Otherwise, it gives the error output and prints error opening file
void Game::saveGame() {
    ofstream file("save.txt");

    if (file.is_open()) {
        file << player.getDay() << endl;
        file << player.getEnergy() << endl;
        file << player.getMoney() << endl;
        file << player.getLocation() << endl;
        file << jojaInfluence << endl;

        file << player.getInventorySize() << endl;

        for (int i = 0; i < static_cast<int>(player.getInventorySize()); i++) {
            file << player.getInventoryItem(i).getName() << endl;
        }

        file << donatedItems.size() << endl;

        for (int i = 0; i < static_cast<int>(donatedItems.size()); i++) {
            file << donatedItems[i] << endl;
        }

        file.close();

        cout << "Game saved." << endl;
    } else {
        cerr << "Error opening file." << endl;
    }
}
// Create an input file stream from file save, if the file is not open it prints No save file found, otherwise It reads each line from the file and sets variables day energy money location inventory count donated count. Then it uses the new variables and set functions to set variables for the whole game. Then it reads inventory count and then the following lines equal to the number of inventory count and for each line, it uses getline to get the name of the item and then it uses the create item from name function to add that item to the player's inventory vector. Then it clears the donated items vector and reads the number of items donated and then reads the following lines equal to the number of items donated and then for each line it uses getline to get the item name and then it adds the item name to the donated items vector. Last it closes the file and prints game loaded. 
void Game::loadGame() {
    ifstream file("save.txt");

    if (!file.is_open()) {
        cout << "No save file found." << endl;
        return;
    }

    int day;
    int energy;
    int money;
    string location;
    int inventoryCount;
    int donatedCount;

    file >> day;
    file >> energy;
    file >> money;
    file.ignore();
    getline(file, location);
    file >> jojaInfluence;

    player.setDay(day);
    player.setEnergy(energy);
    player.setMoney(money);
    player.setLocation(location);

    player.clearInventory();
    file >> inventoryCount;
    file.ignore();

    for (int i = 0; i < inventoryCount; i++) {
        string itemName;
        getline(file, itemName);
        player.addItem(loadItemFromName(itemName));
    }

    donatedItems.clear();
    file >> donatedCount;
    file.ignore();

    for (int i = 0; i < donatedCount; i++) {
        string itemName;
        getline(file, itemName);
        donatedItems.push_back(itemName);
    }

    file.close();

    cout << "Game loaded." << endl;
}