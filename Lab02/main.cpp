#include "Brawler.h"
#include "GameMap.h"
#include "Gadget.h"
#include "TankBrawler.h"
#include "Shield.h"
#include "Box.h"
#include "IDamageable.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "PlayerProfile.h"
#include "LootBox.h"
#include <ctime>
#include <fstream>

void saveMapsToFile(const std::vector<std::shared_ptr<GameMap>>& maps);
void loadMapsFromFile(std::vector<std::shared_ptr<GameMap>>& maps); 

int main () {
    std::srand(static_cast<unsigned int>(std::time(0)));

 std::cout << "Welcome to the Brawler Game!" << std::endl;

 // Create a player profile
 auto player = std::make_unique<PlayerProfile>("Vlaioxss");
 player->loadProgress();

 //Create shop items (loot boxes, etc.)
    std::vector<std::shared_ptr<LootBox>> shopItems;
      shopItems.push_back(std::make_shared<LootBox>("Small Box", 80, 1, 10, 50, 5, 20, 1, 5, 0.01f));
      shopItems.push_back(std::make_shared<LootBox>("Big Box", 500, 1, 50, 200, 20, 50, 5, 20, 0.1f));
      shopItems.push_back(std::make_shared<LootBox>("Mega Box", 1000, 1, 200, 500, 50, 100, 20, 50, 0.2f));

 // Create some game maps
 std::vector<std::shared_ptr<GameMap>> maps;
 loadMapsFromFile(maps);

 if (maps.empty()) {
    maps.push_back(std::make_shared<GameMap>("Sunny Beach", "Showdown", "Beach", "Sunny"));
    maps.push_back(std::make_shared<GameMap>("Dark Forest", "Brawl Ball", "Forest", "Fog"));
    maps.push_back(std::make_shared<GameMap>("Volcanic Crater", "Knockout", "Crater", "None"));

    saveMapsToFile(maps);
}
    

// Create some gadgets for brawlers
 auto MyUniqueGadget2 = std::make_unique<Gadget>("Mega Shield", 2);
 auto MyUniqueGadget3 = std::make_unique<Gadget>("Healing Potion", 4);
 auto MyUniqueGadget4 = std::make_unique<Gadget>("Speed Boost", 5);
 auto MyUniqueGadget5 = std::make_unique<Gadget>("Invisibility Cloak", 1);

 // Create some shields for tank brawlers
 auto BullShield = std::make_unique<Shield>("Reinforced Plating", 3000);

//Create some entities (brawlers and tank brawlers, boxes, etc.)
    std::vector<std::shared_ptr<GameEntity>> entities;
    entities.push_back(std::make_shared<Brawler>("Nita", 5000, 10, 400, Gadget("Mega Shield", 2), 12.0, 5.0, 2));
    entities.push_back(std::make_shared<Brawler>("Colt", 4000, 9, 360, Gadget("Healing Potion", 4), 10.0, 4.0, 3));
    entities.push_back(std::make_shared<Brawler>("Bull", 8000, 9, 500, Gadget("Speed Boost", 5), 10.0, 4.0, 4));
    entities.push_back(std::make_shared<TankBrawler>("Bull", 8000, 9, 500, Gadget("Speed Boost", 5), 50, Shield("Steel", 100), 10.0, 4.0, 4));

// Create some boxes for brawlers to interact with
    entities.push_back(std::make_shared<Box>(10.0, 5.0, 6, 2000));
    entities.push_back(std::make_shared<Box>(12.0, 6.0, 7, 5000));
    entities.push_back(std::make_shared<Box>(14.0, 7.0, 8, 6000));

//Create menu 
int choice;
std::shared_ptr<GameMap> selectedMap = maps[0];
while (true) {
    system("cls");

    std::cout << "\n===============================" << std::endl;
    std::cout << " PLAYER: " << player->getName() << " | Level: " << player->getLevel() << " | Trophies: " << player->getTrophies() << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "1. My Profile" << std::endl;
    std::cout << "2. Shop" << std::endl;
    std::cout << "3. Go Battle!" << std::endl;
    std::cout << "4. Select Brawler" << std::endl;
    std::cout << "5. Select Map" << std::endl;
    std::cout << "6. View Battle Log" << std::endl;
    std::cout << "Enter your choice: ";
    
    if (!(std::cin >> choice)) { 
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    continue;
}
if (choice == 0) break;

if (choice == 777) {
    system("cls");

    std::string pass;
    std::cout << "ADMIN MENU. Enter secret code: ";
    std::cin >> pass;
    if (pass == "chnu2026") {
        bool runningAdminMenu = true;
        while (runningAdminMenu) {
            std::cout << "\n--- ADMIN MENU ---" << std::endl;
            std::cout << "1. Add Brawler" << std::endl;
            std::cout << "2. Add Map" << std::endl;
            std::cout << "3. Add Loot Box" << std::endl;
            std::cout << "4. View All Entities" << std::endl;
            std::cout << "5. Exit Admin Menu" << std::endl;
            std::cout << "Enter your choice: ";
            
            int adminChoice;
            if (!(std::cin >> adminChoice)) { 
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            
            switch (adminChoice) {
                case 1: {
                    system("cls");
                    // Code to add a new brawler
                     std::string name;
                     int hp, powerLvl, gadgetCharges, id;
                     std::cout << "Enter brawler name: ";
                     std::cin >> name;
                     std::cout << "Enter HP: ";
                     std::cin >> hp;
                     std::cout << "Enter Power Level: ";
                     std::cin >> powerLvl;
                     std::cout << "Enter ID: ";
                     std::cin >> id;

                     auto g = std::make_unique<Gadget>("Default Gadget", 3);
                     entities.push_back(std::make_shared<Brawler>(name, hp, powerLvl, 400, Gadget("Default Gadget", 3), 10.0, 5.0, id));
                     std::cout << "Brawler " << name << " added successfully!" << std::endl;
                     break;
                }
                case 2: {
                    system("cls");
                    // Code to add a new map
                     std::string name, mode, environment, modifier;
                     std::cout << "Enter map name: ";
                     std::cin >> name;
                     std::cout << "Enter game mode: ";
                     std::cin >> mode;
                     std::cout << "Enter environment: ";
                     std::cin >> environment;
                     std::cout << "Enter modifier: ";
                     std::cin >> modifier;  

                     maps.push_back(std::make_shared<GameMap>(name, mode, environment, modifier));
                     std::cout << "Map " << name << " added successfully!" << std::endl;
                     system("cls");

                     saveMapsToFile(maps);
                    break;
                }
                case 3: {
                    system("cls");
                    // Code to add a new loot box
                    std::string name; int price;
                    std::cout << "Enter loot box name: ";
                    std::cin >> name;
                    std::cout << "Enter price: ";
                    std::cin >> price;

                        shopItems.push_back(std::make_shared<LootBox>(name, price, 1, 50, 200, 10, 50, 1, 10, 0.1f));
                        std::cout << "Loot Box " << name << " added successfully!" << std::endl;
                    break;
                }
                case 4: {
                    system("cls");

                    std::cout << "\n--- ALL ENTITIES ---" << std::endl;
                    for (const auto& entity : entities) {
                        entity->showInfo();
                        std::cout << "-------------------" << std::endl;
                    }
                    break;
                }
                case 5:
                    system("cls");

                    runningAdminMenu = false;
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
            }
        }
    }

} else {
    switch (choice) {
        case 1: {
            system("cls");

            std::cout << "\n========================================" << std::endl;
            std::cout << "           PLAYER STATISTICS            " << std::endl;
            std::cout << "========================================" << std::endl;

            player->showProfile();

            if (player->getActiveBrawler() != nullptr) {
                std::cout << "Selected Brawler: [" << player->getActiveBrawler()->getName() << "]" << std::endl;
            } else {
                std::cout << "Selected Brawler: None (Go to Shop!)" << std::endl;
            }

            std::cout << "========================================" << std::endl;
            std::cout << "Press Enter to return to menu...";
            std::cin.ignore(10000, '\n');
            std::cin.get();
            break;
        }

        case 2: {
            system("cls");

            std::cout << "\n=========  BRAWL SHOP  =========" << std::endl;
            std::cout << "Your balance: " << player->getCoins() << " Coins | " << player->getGems() << " Gems" << std::endl;
            std::cout << "------------------------------------" << std::endl;

            for (size_t i = 0; i < shopItems.size(); ++i) {
                std::cout << i + 1 << ". BOX: " << shopItems[i]->getName() 
                          << " | Price: " << shopItems[i]->getPrice() << " Coins" << std::endl;
            }

            int brawlerOfferIdx = (int)shopItems.size() + 1;
            int gemsToCoinsIdx = (int)shopItems.size() + 2;

            std::cout << brawlerOfferIdx << ". SPECIAL: El Primo (Brawler) | Price: 50 Gems" << std::endl;
            std::cout << gemsToCoinsIdx << ". PACK: 500 Coins | Price: 30 Gems" << std::endl;
            std::cout << "0. Back to Main Menu" << std::endl;
            std::cout << "------------------------------------" << std::endl;

            int shopChoice;
            std::cout << "Select item to buy: ";
            std::cin >> shopChoice;

            if (shopChoice == 0) break;

            try {
                if (shopChoice > 0 && shopChoice <= (int)shopItems.size()) {
                    auto selectedBox = shopItems[shopChoice - 1];
                    player->spendCoins(selectedBox->getPrice());
                    selectedBox->openBox(*player);
                    std::cout << "Purchase successful!" << std::endl;
                } 
                else if (shopChoice == brawlerOfferIdx) {
                    player->spendGems(50);
                    auto elPrimo = std::make_shared<Brawler>("El Primo", 6000, 12, 500, Gadget("Suplex", 3), 10.0, 5.0, 99);
                    player->addBrawler(elPrimo);
                    std::cout << "ELLLLL PRIMOOOOOO! New brawler unlocked!" << std::endl;
                }
                else if (shopChoice == gemsToCoinsIdx) {
                    player->spendGems(30);
                    player->addCoins(500);
                    std::cout << "Exchanged 30 Gems for 500 Coins!" << std::endl;
                }
                else {
                    std::cout << "Invalid shop item!" << std::endl;
                }
            } 
            catch (const std::runtime_error& e) {
                std::cout << "\n TRANSACTION FAILED: " << e.what() << std::endl;
            }

            player->saveProgress();

            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(10000, '\n');
            std::cin.get();
            break;
        }

        case 3: {
            system("cls");

            if (player->getActiveBrawler() == nullptr) {
                std::cout << "\n  [ERROR] No brawler selected! Go to Menu #4 first." << std::endl;
                break;
            }

            auto fighter = player->getActiveBrawler();
            auto enemy = std::make_shared<Brawler>("Bot Bull", 4500, 10, 300, Gadget("Shield", 3), 12.0, 6.0, 77);
            std::cout << "\n---  BATTLE START: " << fighter->getName() << " VS " << enemy->getName() << "  ---" << std::endl;
            std::cout << " Location: " << selectedMap->getName() << " [" << selectedMap->getMode() << "]" << std::endl;

            while (fighter->getHP() > 0 && enemy->getHP() > 0) {
                enemy->takeDamage(fighter->getAttackDamage());
                std::cout << fighter->getName() << " attacks! Enemy HP: " << (enemy->getHP() > 0 ? enemy->getHP() : 0) << std::endl;

                if (enemy->getHP() <= 0) break;

                fighter->takeDamage(enemy->getAttackDamage());
                std::cout << enemy->getName() << " hits back! Your HP: " << (fighter->getHP() > 0 ? fighter->getHP() : 0) << std::endl;
            }

            if (fighter->getHP() > 0) {
                std::cout << "\n VICTORY!" << std::endl;
                std::cout << " +10 Trophies | +30 Coins | +60 XP" << std::endl;
                player->winBattle(10);
                player->gainExperience(60);
                player->addCoins(30);
            } else {
                std::cout << "\n DEFEAT... " << std::endl;
                std::cout << "-5 Trophies" << std::endl;
                player->loseBattle(5);
            }

            fighter->resetHp();
            player->saveProgress();
            std::cout << "\n--- BATTLE END ---" << std::endl;

            std::cout << "------------------------------------------" << std::endl;
            std::cout << "Press Enter to return to menu...";
            std::cin.ignore(10000, '\n');
            std::cin.get();
            break;
        }

        case 4: {
            system("cls");

            std::cout << "\n--- YOUR BRAWLERS ---" << std::endl;
            int count = player->getBrawlerCount();

            if (count == 0) {
                std::cout << "You don't have any brawlers yet! Go to Shop" << std::endl;
            } else {
                for (int i = 0; i < count; ++i) {
                    std::cout << i << ". " << player->getBrawlerName(i) << std::endl;
                }
                int bChoice;
                std::cout << "Select brawler index to play: ";
                std::cin >> bChoice;
                try {
                    player->selectBrawler(bChoice);
                    std::cout << "Active brawler set to: " << player->getActiveBrawler()->getName() << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cout << "[ERROR] Invalid index! " << e.what() << std::endl;
                }
            }
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "Press Enter to return to menu...";
            std::cin.ignore(10000, '\n');
            std::cin.get();
            break;
        }

        case 5: {
            system("cls");

            std::cout << "\n--- AVAILABLE MAPS ---" << std::endl;
            if (maps.empty()) {
                std::cout << "No maps found!" << std::endl;
            } else {
                for (size_t i = 0; i < maps.size(); ++i) {
                    std::cout << i << ". " << maps[i]->getName() << " | Mode: " << maps[i]->getMode() << std::endl;
                }
                int mChoice;
                std::cout << "Select map index: ";
                std::cin >> mChoice;
                if (mChoice >= 0 && mChoice < (int)maps.size()) {
                    selectedMap = maps[mChoice];
                    std::cout << "Map successfully changed to: " << selectedMap->getName() << std::endl;
                } else {
                    std::cout << "[ERROR] Invalid map index!" << std::endl;
                }
            }
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "Press Enter to return to menu...";
            std::cin.ignore(10000, '\n');
            std::cin.get();
            break;
        }

        case 6: {
            system("cls");

            std::cout << "\n--- BATTLE HISTORY ---" << std::endl;
            player->showBattleLog();
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "Press Enter to return to menu...";
            std::cin.ignore(10000, '\n');
            std::cin.get();
            break;
        }

        default:
            std::cout << "Invalid choice! Try again." << std::endl;
            break;
    }
    }

}
return 0;
}

//Function realization
void saveMapsToFile(const std::vector<std::shared_ptr<GameMap>>& maps) {
    std::ofstream file("maps.txt");
    
    if (file.is_open()){
        for (const auto& map : maps) {
            file << map->getName() << "," << map->getMode() << "," << map->getEnvironment() << "," << map->getModifier() << std::endl;
        }
        file.close();
        std::cout << "Maps saved to maps.txt successfully!" << std::endl;
    } else {
        std::cout << "Error opening file for writing!" << std::endl;
    }
}

void loadMapsFromFile(std::vector<std::shared_ptr<GameMap>>& maps) {
    std::ifstream file("maps.txt");
    if (file.is_open()) {
        std::string name, mode, environment, modifier;
        while (std::getline(file, name, ',') && std::getline(file, mode, ',') && std::getline(file, environment, ',') && std::getline(file, modifier)) {
            maps.push_back(std::make_shared<GameMap>(name, mode, environment, modifier));
        }
        file.close();
        std::cout << "Maps loaded from maps.txt successfully!" << std::endl;
    } else {
        std::cout << "Error opening file for reading!" << std::endl;
    }
}
