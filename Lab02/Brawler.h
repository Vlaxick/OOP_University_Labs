#pragma once
#include <iostream>
#include <string>
#include "Gadget.h"

class Brawler {
    std::string name;
    int hp;
    int powerlvl;
    Gadget gadget;
    static int brawlerCount;
    
    public:
    Brawler(std::string name_val, int hp_val, int powerlvl_val, Gadget gadget_val);
    Brawler(std::string name_val);
    Brawler(const Brawler &other);
    Brawler(Brawler &&other);
    ~Brawler();

    void attack();
    void showInfo() const;
    void useAbility();
    Brawler& upgrade();
    static int getBrawlerCount();
};