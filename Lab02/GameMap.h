#pragma once
#include <iostream>
#include <string>

class GameMap {
    std::string name;
    std::string gamemode;
    std::string environment;
    std::string modifier;

    public:
    GameMap(std::string name_val = "Cavern Churn ", std::string gamemode_val = "Showdown", std::string environment_val = "Desert", std::string modifier_val = "None");
    ~GameMap();
    void Rules();
    void checkEnd(int gamerule);
};