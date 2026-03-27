#include <iostream>
#include "GameEntity.h"

GameEntity::GameEntity(double x_val, double y_val, int id_val) 
    : x{x_val}, y{y_val}, id{id_val}, isActive{true} 
{
    std::cout << "Object created at position (" << x << ", " << y << ") with ID: " << id << std::endl;
}

GameEntity::~GameEntity() {
    std::cout << "Object with ID: " << id << " has been destroyed." << std::endl;
}

void GameEntity::showPosition() const {
    std::cout << "Object ID: " << id << " is at position (" << x << ", " << y << ")" << std::endl;
}

void GameEntity::move(double dx, double dy) {
    x += dx;
    y += dy;
    std::cout << "Object ID: " << id << " moved to position (" << x << ", " << y << ")" << std::endl;
}

void GameEntity::update() {
   
}

double GameEntity::getSpeed() const {
    return 1.0; 
}

void GameEntity::interact(GameEntity& other) {
    std::cout << "Object ID: " << id << " interacts with Object ID: " << other.id << std::endl;
}