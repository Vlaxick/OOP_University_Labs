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

int main () {
    std::srand(static_cast<unsigned int>(std::time(0)));

 std::cout << "Welcome to the Brawler Game!" << std::endl;

 // Create a player profile
 auto player = std::make_unique<PlayerProfile>("Vlaioxss");

 //Create shop items (loot boxes, etc.)
    std::vector<std::shared_ptr<LootBox>> shopItems;
        shopItems.push_back(std::make_shared<LootBox>("Small Box", 80, 10, 50, 5, 20, 1, 5, 0.01f));
        shopItems.push_back(std::make_shared<LootBox>("Big Box", 500, 50, 200, 20, 50, 5, 20, 0.1f));
        shopItems.push_back(std::make_shared<LootBox>("Mega Box", 1000, 200, 500, 50, 100, 20, 50, 0.2f));

 // Create some game maps
 std::vector<std::shared_ptr<GameMap>> maps;
    maps.push_back(std::make_shared<GameMap>("Sunny Beach", "Showdown", "Beach", "Sunny"));
    maps.push_back(std::make_shared<GameMap>("Dark Forest", "Brawl Ball", "Forest", "Fog"));
    maps.push_back(std::make_shared<GameMap>("Volcanic Crater", "Knockout", "Crater", "None"));

// Create some gadgets for brawlers
 auto MyUniqueGadget2 = std::make_unique<Gadget>("Mega Shield", 2);
 auto MyUniqueGadget3 = std::make_unique<Gadget>("Healing Potion", 4);
 auto MyUniqueGadget4 = std::make_unique<Gadget>("Speed Boost", 5);
 auto MyUniqueGadget5 = std::make_unique<Gadget>("Invisibility Cloak", 1);

 // Create some shields for tank brawlers
 auto BullShield = std::make_unique<Shield>("Reinforced Plating", 3000);

//Create some entities (brawlers and tank brawlers, boxes, etc.)
    std::vector<std::shared_ptr<GameEntity>> entities;
    entities.push_back(std::make_shared<Brawler>("Nita", 5000, 10, std::move(MyUniqueGadget2), 12.0, 5.0, 2));
    entities.push_back(std::make_shared<Brawler>("Colt", 4000, 9, std::move(MyUniqueGadget3), 10.0, 4.0, 3));
    entities.push_back(std::make_shared<TankBrawler>("Bull", 8000, 9, std::move(MyUniqueGadget4), 10.0, 4.0, 4));
    entities.push_back(std::make_shared<TankBrawler>("Jessy", 4500, 8, std::move(MyUniqueGadget5), 12.0, 6.0, 5, 10, std::move(BullShield)));

// Create some boxes for brawlers to interact with
    entities.push_back(std::make_shared<Box>("Health Box", 2000, 10.0, 5.0, 6));
    entities.push_back(std::make_shared<Box>("Ammo Box", 5000, 12.0, 6.0, 7));
    entities.push_back(std::make_shared<Box>("Power-Up Box", 6000, 14.0, 7.0, 8));
}

