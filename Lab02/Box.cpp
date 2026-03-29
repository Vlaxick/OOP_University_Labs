#include <iostream>
#include "Box.h"

Box::Box(double x_val, double y_val, int id_val, int health_val) 
    : GameEntity(x_val, y_val, id_val), BoxHealth{health_val} {
    std::cout << "Box created at position (" << x_val << ", " << y_val << ") with health: " << BoxHealth << std::endl;
}


Box::~Box() {
    std::cout << "Box with ID " << id << " has been destroyed." << std::endl;
}

void Box::takeDamage(int amount) {
    BoxHealth -= amount;
    std::cout << "Box took " << amount << " damage! Remaining health: " << BoxHealth << std::endl;
    if (BoxHealth <= 0) {
        std::cout << "Box destroyed! You get 1 power-up!" << std::endl;
    }
}

void Box::update() {
    // For this simple example, the box doesn't have any behavior to update.
}