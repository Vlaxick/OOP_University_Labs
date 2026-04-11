#pragma once
#include <iostream>
#include <string>

class Shield {
    public:
    int durability;
    std :: string shieldType;
    Shield(std::string shieldType_val, int durability_val);
    ~Shield();

    void reduceDurability(int damage);
};