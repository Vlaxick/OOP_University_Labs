#pragma once
#include <iostream>

class GameEntity {
    protected:
    bool isActive;
    double x, y;
    int id;

    public:
    GameEntity(double x_val, double y_val, int id_val);
    virtual ~GameEntity();

    virtual void showPosition() const;
    virtual void move(double dx, double dy);
    virtual void update() = 0;
    virtual double getSpeed() const;
    virtual void interact(GameEntity& other);
};