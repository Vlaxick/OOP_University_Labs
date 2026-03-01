#include "GameMap.h"
#include <iostream>

GameMap::GameMap(std::string name_val, std::string gamemode_val, std::string environment_val, std::string modifier_val)
  : name{name_val}, gamemode{gamemode_val}, environment{environment_val}, modifier{modifier_val}
  {
    std::cout << "Game Map " << name << " Gamemode " << gamemode << " Environment " << environment << " Modifier " << modifier << std::endl;
  }

  GameMap::~GameMap() {
    std::cout << "Game Over" << std::endl;
  }

  void GameMap::Rules() {
    if (gamemode == "Showdown") {
        std::cout << "The last brawler standing wins!" << std::endl;
    } else if (gamemode == "Brawl Ball") {
        std::cout << "Score 2 goals to win!" << std::endl;
    } else if (gamemode == "Heist") {
        std::cout << "Defend your safe while trying to break the enemy's safe!" << std::endl;
    } else if (gamemode == "Bounty") {
        std::cout << "Collect stars by defeating opponents, the team with the most stars wins!" << std::endl;
    } else if (gamemode == "Siege") {
        std::cout << "Collect bolts to build a robot and destroy the enemy's base!" << std::endl;
    } else {
        std::cout << "Unknown gamemode!" << std::endl;
    }
  }

  void GameMap::checkEnd(int gamerule) {
     if (gamemode == "Showdown" && gamerule == 1) {
        std::cout << "Game Over! You Win!" << std::endl;
    } else if (gamemode == "Brawl Ball" && gamerule == 2) {
        std::cout << "Game Over! You Team Win!" << std::endl;
    } else if (gamemode == "Heist" && gamerule == 0) {
        std::cout << "Game Over! Your Team Win!" << std::endl;
    } else if (gamemode == "Bounty" && gamerule == 10) {
        std::cout << "Game Over! You Team Win!" << std::endl;
    } else {
        std::cout << "Curent score: " << gamerule <<std::endl;
    }
  }