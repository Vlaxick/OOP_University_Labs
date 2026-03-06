#pragma once
#include <iostream>
#include <string>
#include "Gadget.h"

class Brawler {
    std::string name;
    int hp;
    int powerlvl;
    Gadget gadget;
    
    public:
    Brawler(std::string name_val, int hp_val, int powerlvl_val, Gadget gadget_val);
    Brawler(std::string name_val);
    ~Brawler();

    void attack();
    void showInfo();
    void useAbility();
};