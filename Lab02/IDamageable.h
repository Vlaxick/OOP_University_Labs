#pragma once

class IDamageable {
public:
    virtual ~IDamageable() {};
    virtual void takeDamage(int damage) = 0;
};