#include "Game.h"

#include <iostream>
#include <limits>

using namespace std;

Game::Game() {
    player = Player();
    jojaInfluence = 0;
    gameOver = false;
    won = false;
    setupGame();
}

Game::Game(string playerName) {
    player = Player(playerName);
    jojaInfluence = 0;
    gameOver = false;
    won = false;
    setupGame();
}

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
        "The Community Center needs one final bundle. Check the board often.",
        Item("Parsnip", "Crop", 20, true)));
    characters.push_back(Character("Willy", "Beach",
        "The sea is generous if you have energy to fish.",
        Item("Sunfish", "Fish", 30, true)));
    characters.push_back(Character("Clint", "Mines",
        "A little copper can go a long way.",
        Item("Copper Ore", "Mineral", 15, true)));
    characters.push_back(Character("Linus", "Forest",
        "The forest provides for anyone who respects it.",
        Item("Wild Horseradish", "Forage", 25, true)));
}

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
}

void Game::displayMap() {
    cout << endl;
    cout << "Map:" << endl;
    cout << "        [Mines]" << endl;
    cout << "           |" << endl;
    cout << "[Farm] -- [Town] -- [Community Center] -- [Beach]" << endl;
    cout << "   |          |" << endl;
    cout << "[Forest]  [JojaMart]" << endl;
    cout << "Current Location: " << player.getLocation() << endl;
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
    cout << "5. Visit Community Center" << endl;
    cout << "6. Visit JojaMart" << endl;
    cout << "7. End day" << endl;
    cout << "8. Quit" << endl;
    cout << "Choice: ";
}

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

void Game::movePlayer() {
    int choice;

    cout << endl;
    cout << "Where would you like to go?" << endl;
    for (int i = 0; i < static_cast<int>(locations.size()); i++) {
        cout << i + 1 << ". " << locations[i] << endl;
    }
    cout << "Choice: ";
    choice = getNumberChoice();

    if (choice >= 1 && choice <= static_cast<int>(locations.size())) {
        player.setLocation(locations[choice - 1]);
        cout << "You travel to " << player.getLocation() << "." << endl;
    } else {
        cout << "That location does not exist." << endl;
    }
}

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

void Game::visitCommunityCenter() {
    displayBundle();

    for (int i = 0; i < static_cast<int>(bundleNeeds.size()); i++) {
        if (!alreadyDonated(bundleNeeds[i]) && player.hasItem(bundleNeeds[i])) {
            player.removeItem(bundleNeeds[i]);
            donatedItems.push_back(bundleNeeds[i]);
            cout << "You donated " << bundleNeeds[i] << " to the bundle." << endl;
            return;
        }
    }

    cout << "You do not have any needed bundle items to donate right now." << endl;
}

void Game::visitJojaMart() {
    int choice;

    cout << endl;
    cout << "Morris says: Joja can help, for a price." << endl;
    cout << "1. Buy an Egg bundle item - 40g" << endl;
    cout << "2. Buy Joja Cola energy boost - 20g" << endl;
    cout << "3. Leave" << endl;
    cout << "Choice: ";
    choice = getNumberChoice();

    if (choice == 1) {
        if (player.spendMoney(40)) {
            player.addItem(Item("Egg", "Animal Product", 40, true));
            jojaInfluence++;
            cout << "You bought an Egg. Joja Influence increased." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
    } else if (choice == 2) {
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
