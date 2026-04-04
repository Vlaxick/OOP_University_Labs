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
    void showProfile() const;
    void showBattleLog() const;
    void spendCoins(int coins);
    void spendGems(int gems);
    void spendPowerPoints(int points);
};
