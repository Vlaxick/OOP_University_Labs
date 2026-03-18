#pragma once
#include "Brawler.h"
#include "Shield.h"
#include <iostream>

class TankBrawler : public Brawler {
    protected:
    int armor;
    double damageReduction = 0.2; // Reduces damage by 20%
    Shield activeShield;
    public:
    TankBrawler(std::string name_val, int hp_val, int powerlvl_val, Gadget gadget_val, int armor_val, Shield shield_val, double x_val = 0.0, double y_val = 0.0, int id_val = 0);
    TankBrawler(const TankBrawler &other);
    TankBrawler(TankBrawler &&other) noexcept;
    TankBrawler &operator=(const TankBrawler &rhs) noexcept;
    ~TankBrawler();

    void takeDamage(int damage);
};