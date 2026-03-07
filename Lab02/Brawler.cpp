#include "Brawler.h"
#include <iostream>

Brawler::Brawler(std::string name_val, int hp_val, int powerlvl_val, Gadget gadget_val) 
    : name{name_val}, hp{hp_val}, powerlvl{powerlvl_val}, gadget{gadget_val} 
{
    std::cout << "Brawler: " << name << " Hp: " << hp << " Power Level: " << powerlvl << std::endl;
}

Brawler::Brawler(std::string name_val) 
    : Brawler(name_val, 3440, 11, Gadget("Default Gadget")) 
{
    std::cout << "Delegating constructor used for " << name << std::endl;
}

Brawler::Brawler(const Brawler &other) 
    : name{other.name}, hp{other.hp}, powerlvl{other.powerlvl}, gadget{other.gadget} 
{
    std::cout << "Copy constructor called for " << name << std::endl;
}

Brawler ::Brawler(Brawler &&other) 
    : name{std::move(other.name)}, hp{other.hp}, powerlvl{other.powerlvl}, gadget{std::move(other.gadget)} 
{
    other.hp = 0;
    other.powerlvl = 0;
    std::cout << "Move constructor called for " << name << std::endl;
}

Brawler::~Brawler() {
    std::cout << "Brawler " << name << " has been destroyed by Leon" << std::endl;
}

void Brawler::showInfo() const {
    std::cout << "--- Brawler Stats ---" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hp: " << hp << std::endl;
    std::cout << "Power Level: " << powerlvl << std::endl;
    std::cout << "---------------------" << std::endl;
}

void Brawler::useAbility() {
    std::cout << name << " uses his gadget: ";
    gadget.use(); 
}

Brawler& Brawler::upgrade() {
    if (this->powerlvl >= 11) {
        std::cout << name << " has max power level!" << std::endl;
    } else {
    this->powerlvl += 1;
    std::cout << name << " has been upgraded to: " << powerlvl << std::endl;
    }
    return *this;
}