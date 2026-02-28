#pragma once
#include <iostream>
#include <string>

class Brawler {
    private:
    std::string name;
    int hp;
    int powerlvl;
    
    public:
    Brawler(std::string name_val = "Gloybert", int hp_val = 3770, int powerlvl_val = 11);
    Brawler(std::string name_val);
    ~Brawler();

    void attack();
    void showInfo();
};