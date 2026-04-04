#include "LootBox.h"

LootBox::LootBox(const std::string& type, int price, int minCoins, int maxCoins, int minPowerPoints, int maxPowerPoints, int minGems, int maxGems, float brawlerDropRate)
: boxType(type), price(price), minCoins(minCoins), maxCoins(maxCoins), minPowerPoints(minPowerPoints), maxPowerPoints(maxPowerPoints), minGems(minGems), maxGems(maxGems), BrawlerDropRate(brawlerDropRate) {
}

void LootBox::openBox(PlayerProfile& player) {
    // 1. Рахуємо, скільки випало монет (випадкове число від min до max)
    int range = maxCoins - minCoins;
    int coinsReward = minCoins + (std::rand() % (range + 1));

    // 2. Рахуємо, скільки випало гемів
    int gemsRange = maxGems - minGems;
    int gemsReward = minGems + (std::rand() % (gemsRange + 1));

    // 3. Рахуємо, скільки випало поінтів сили
    int powerPointsRange = maxPowerPoints - minPowerPoints;
    int powerPointsReward = minPowerPoints + (std::rand() % (powerPointsRange + 1));

    // 3. Віддаємо ці гроші в "гаманець" гравця
    player.addCoins(coinsReward);
    player.addGems(gemsReward);
    player.addPowerPoints(powerPointsReward);

    // 4. Пишемо в консоль, що саме отримав гравець
    std::cout << "--- BOX OPENED: " << boxType << " ---" << std::endl;
    std::cout << "Coins: +" << coinsReward << std::endl;
    std::cout << "Gems: +" << gemsReward << std::endl;

    if ((std::rand() % 100) < (BrawlerDropRate * 100)) {
        std::cout << "!!! UNLOCKED NEW BRAWLER !!!" << std::endl;
    }
}