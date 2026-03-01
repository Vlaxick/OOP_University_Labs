#include "Gadget.h"
#include <iostream>

Gadget::Gadget(std::string name_val, int charges_val) 
    : name{name_val}, charges{charges_val}
{
    std::cout << "Gadget " << name << "with " << charges << " charges." << std::endl;
}

Gadget::~Gadget() {
    std::cout << "Gadget " << name << " has been used 3 times." << std::endl;
}

void Gadget::use() {
    if (charges > 0) {
        std::cout << "Using " << name << ". Charges left: " << --charges << std::endl;
    } else {
        std::cout << name << " has no charges left." << std::endl;
    }
}