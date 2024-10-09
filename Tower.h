// INCOMPLETE

#ifndef TOWER_H
#define TOWER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

class Tower {
private:
    Vector2f position;  // Position of the tower
    int damage;
    float attackSpeed;

public:
    Tower(int damage, float attackSpeed, Vector2f position);

    Vector2f getPosition() const;  // Get the position of the tower
    int getDamage() const;
    float getAttackSpeed() const;
};

#endif
