#pragma once
#include <iostream>

class GameEntity {
    protected:
    bool isActive;
    double x, y;
    int id;

    public:
    GameEntity(double x_val, double y_val, int id_val);
    ~GameEntity();

    void showPosition() const;
    void move(double dx, double dy);
};