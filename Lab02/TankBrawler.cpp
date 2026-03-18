#include <iostream>
#include "TankBrawler.h"
#include "Shield.h"
#include "Brawler.h"

TankBrawler::TankBrawler(std::string name_val, int hp_val, int powerlvl_val, Gadget gadget_val, int armor_val, Shield shield_val, double x_val, double y_val, int id_val) 
    : Brawler(name_val, hp_val, powerlvl_val, gadget_val, x_val, y_val, id_val), armor{armor_val}, activeShield{shield_val} 
{
    std::cout << "TankBrawler: " << name << " with Armor: " << armor << " has been created." << std::endl;
}

TankBrawler::TankBrawler(const TankBrawler &other) 
    : Brawler(other), armor{other.armor}, activeShield{other.activeShield} 
{
    std::cout << "Copy constructor called for TankBrawler: " << name << std::endl;
}

TankBrawler::TankBrawler(TankBrawler &&other) noexcept 
    : Brawler(std::move(other)), armor{std::move(other.armor)}, activeShield{std::move(other.activeShield)} 
{
    std::cout << "Move constructor called for TankBrawler: " << name << std::endl;
}

TankBrawler &TankBrawler::operator=(const TankBrawler &rhs) noexcept {
    if (this == &rhs) {
        return *this; 
    }
    Brawler::operator=(rhs); 
    this->armor = rhs.armor;
    this->activeShield = rhs.activeShield;
    std::cout << "Copy assignment operator called for TankBrawler: " << name << std::endl;
    return *this;
}

TankBrawler::~TankBrawler() {
    std::cout << "TankBrawler " << name << " has been destroyed." << std::endl;
}

void TankBrawler::takeDamage(int damage) {
    std::cout << "\n--- Tank is hit for " << damage << " damage ---" << std::endl;

    if (activeShield.durability > 0) {
        activeShield.durability -= 10; 
        damage -= 10;
        std::cout << "Shield blocked 10 damage. Shield left: " << activeShield.durability << std::endl;
    }

    if (damage > 0) {
        hp -= damage;
        if (hp < 0) hp = 0;
        std::cout << "Final damage to HP: " << damage << ". Current HP: " << hp << std::endl;
    }
}

