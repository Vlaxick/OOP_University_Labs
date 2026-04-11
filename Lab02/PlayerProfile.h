#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Brawler.h"

class PlayerProfile {
private:
    std::string playerName;
    int playerLevel;
    int playerExperience;
    int playerTrophies;
    int playerCoins;
    int playerPowerPoints;
    int playerGems;
    std::vector<std::shared_ptr<Brawler>> playerBrawlers;
    std::shared_ptr<Brawler> selectedBrawler;
    std::vector<std::string> battleLog;
public:
    PlayerProfile(const std::string& name);
    PlayerProfile();
    void addBrawler(std::shared_ptr<Brawler> newBrawler);
    void selectBrawler(int index);
    void gainExperience(int exp);
    void winBattle(int trophiesGained);
    void loseBattle(int trophiesLost);
    void addCoins(int coins);
    void addGems(int gems);
    void addPowerPoints(int points);
    void showProfile() const;
    void showBattleLog() const;
    void spendCoins(int coins);
    void spendGems(int gems);
    void spendPowerPoints(int points);
    int getLevel() const;
    int getExperience() const;
    int getTrophies() const;
    int getCoins() const;
    int getGems() const;
    int getPowerPoints() const;
    std::string getName() const;
    std::shared_ptr<Brawler> getActiveBrawler() const;
    int getBrawlerCount() const;
    std::string getBrawlerName(int index) const;
    void saveProgress() const;
    void loadProgress();
};
