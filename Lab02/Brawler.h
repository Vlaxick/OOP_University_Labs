#pragma once
#include "GameEntity.h"
#include <iostream>
#include <string>
#include "Gadget.h"

class Brawler : public GameEntity {
    static int brawlerCount;

    protected:
    std::string name;
    int hp;
    int powerlvl;
    Gadget gadget;
    
    public:
    Brawler(std::string name_val, int hp_val, int powerlvl_val, Gadget gadget_val, double x_val = 0.0, double y_val = 0.0, int id_val = 0);
    Brawler(std::string name_val);
    Brawler(const Brawler &other);
    Brawler(Brawler &&other) noexcept;
    virtual ~Brawler();

    friend std::ostream &operator<<(std::ostream &os, const Brawler &brawler);
    virtual void attack();
    void showInfo() const;
    virtual void takeDamage(int damage);
    virtual void useAbility();
    Brawler& upgrade();
    static int getBrawlerCount();
    Brawler& operator=(const Brawler &rhs) noexcept; 
    bool operator==(const Brawler &rhs) const;
    Brawler& operator++(); 
};