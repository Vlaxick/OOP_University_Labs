#include <iostream>
#include "Shield.h"

Shield::Shield(std::string shieldType_val, int durability_val) 
    : shieldType{shieldType_val}, durability{durability_val} 
{
    std::cout << "Creating Shield: " << shieldType << " with durability: " << durability << std::endl;
}

Shield::~Shield() {
    std::cout << "Shield: " << shieldType << " has been destructed" << std::endl;
}

void Shield::reduceDurability(int damage) {
    durability -= damage; 
    if (durability < 0) {
        durability = 0; 
    }
    std::cout << "Shield durability reduced by " << damage 
              << ". Remaining durability: " << durability << std::endl;
}