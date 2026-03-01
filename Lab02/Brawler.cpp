#include "Brawler.h"
#include <iostream>

Brawler::Brawler(std::string name_val, int hp_val, int powerlvl_val) 
    : name{name_val}, hp{hp_val}, powerlvl{powerlvl_val} 
{
    std::cout << "Brawler: " << name << " Hp: " << hp << " Power Level: " << powerlvl << std::endl;
}

Brawler::Brawler(std::string name_val) 
    : Brawler(name_val, 3440, 11) 
{
    std::cout << "Delegating constructor used for " << name << std::endl;
}

Brawler::~Brawler() {
    std::cout << "Brawler " << name << " has been destroyed by Leon" << std::endl;
}

void Brawler::showInfo() {
    std::cout << "--- Brawler Stats ---" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hp: " << hp << std::endl;
    std::cout << "Power Level: " << powerlvl << std::endl;
    std::cout << "---------------------" << std::endl;
}