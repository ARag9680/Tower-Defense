// INCOMPLETE

#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>

class Tower {
private:
    sf::Vector2f position;  // Position of the tower
    int damage;
    float attackSpeed;

public:
    Tower(int damage, float attackSpeed, sf::Vector2f position);

    sf::Vector2f getPosition() const;  // Get the position of the tower
    int getDamage() const;
    float getAttackSpeed() const;
};

#endif
