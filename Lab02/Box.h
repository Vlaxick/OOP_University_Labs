#pragma once
#include "GameEntity.h"
#include "IDamageable.h"


class Box : public GameEntity, public IDamageable {
    int BoxHealth;
public:
Box (double x_val, double y_val, int id_val, int health_val);
~Box() override;
void takeDamage(int amount) override;
void update() override;
};