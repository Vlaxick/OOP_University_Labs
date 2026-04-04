#include "PlayerProfile.h"
#include <iostream>

PlayerProfile::PlayerProfile(const std::string& name) 
: playerName(name), playerLevel(1), playerExperience(0), playerTrophies(0), playerCoins(0), playerPowerPoints(0), playerGems(0) 
{
addBrawler(std::make_shared<Brawler>("Shelly", 6000, 11, std::make_unique<Gadget>("Super Blaster", 3), 15.0, 6.0, 1));

selectBrawler(0);
}

void PlayerProfile::addBrawler(std::shared_ptr<Brawler> newBrawler) {
    playerBrawlers.push_back(newBrawler);
}

void PlayerProfile::selectBrawler(int index) {
    if (index < 0 || index >= playerBrawlers.size()) {
        throw std::out_of_range("Invalid brawler index!");
    }
    selectedBrawler = playerBrawlers[index];
}

void PlayerProfile::gainExperience(int exp) {
    playerExperience += exp;
    while (playerExperience >= playerLevel * 100) {
        playerExperience -= playerLevel * 100;
        playerLevel++;
    }
}

void PlayerProfile::winBattle(int trophiesGained) {
    playerTrophies += trophiesGained;
    battleLog.push_back("Won a battle and gained " + std::to_string(trophiesGained) + " trophies!");
}

void PlayerProfile::loseBattle(int trophiesLost) {
    playerTrophies -= trophiesLost;
    battleLog.push_back("Lost a battle and lost " + std::to_string(trophiesLost) + " trophies!");
}

void PlayerProfile::addCoins(int coins) {
    playerCoins += coins;
}

void PlayerProfile::addGems(int gems) {
    playerGems += gems;
}

void PlayerProfile::showProfile() const {
    std::cout << "Player Name: " << playerName << std::endl;
    std::cout << "Level: " << playerLevel << std::endl;
    std::cout << "Experience: " << playerExperience << std::endl;
    std::cout << "Trophies: " << playerTrophies << std::endl;
    std::cout << "Coins: " << playerCoins << std::endl;
    std::cout << "Power Points: " << playerPowerPoints << std::endl;
    std::cout << "Gems: " << playerGems << std::endl;
    std::cout << "Brawlers Owned: " << playerBrawlers.size() << std::endl;
}

void PlayerProfile::showBattleLog() const {
    std::cout << "Battle Log:" << std::endl;
    for (const auto& logEntry : battleLog) {
        std::cout << logEntry << std::endl;
    }
}

void PlayerProfile::spendCoins(int coins) {
    if (coins > playerCoins) {
        throw std::runtime_error("Not enough coins!");
    }
    playerCoins -= coins;
}

void PlayerProfile::spendGems(int gems) {
    if (gems > playerGems) {
        throw std::runtime_error("Not enough gems!");
    }
    playerGems -= gems;
}

void PlayerProfile::spendPowerPoints(int points) {
    if (points > playerPowerPoints) {
        throw std::runtime_error("Not enough power points!");
    }
    playerPowerPoints -= points;
}
