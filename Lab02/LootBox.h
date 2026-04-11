#pragma once
#include <iostream>
#include <string>
#include "PlayerProfile.h"

class LootBox {
private:
    std::string boxType;
    int price;
    int priceType;
    int minCoins;
    int maxCoins;
    int maxPowerPoints;
    int minPowerPoints;
    int maxGems;
    int minGems;
    float BrawlerDropRate;
public:
    LootBox(const std::string& type, int price, int priceType, int minCoins, int maxCoins, int minPowerPoints, int maxPowerPoints, int minGems, int maxGems, float brawlerDropRate);
    void openBox(PlayerProfile& player);
    std::string getName() const {
        return boxType;
    }
    int getPrice() const {
        return price;
    }
};