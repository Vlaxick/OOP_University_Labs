#pragma once
#include <iostream>
#include <string>

class Brawler {
    private:
    std::string name;
    int hp;
    int powerlvl;
    
    public:
    Brawler(std::string name_val, int hp_val, int powerlvl_val);
    Brawler(std::string name_val);
    ~Brawler();

    void attack();
    void showInfo();
};