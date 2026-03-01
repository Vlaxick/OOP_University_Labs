#pragma once
#include <iostream>
#include <string>

class Gadget {
    private:
    std::string name;
    int charges;

    public:
    Gadget(std::string name_val = "Gloybert's Gadget", int charges_val = 3);
    ~Gadget();
    void use();
};