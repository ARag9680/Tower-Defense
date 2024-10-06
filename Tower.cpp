// INCOMPLETE

#include "Tower.h"

Tower::Tower(int damage, float attackSpeed, sf::Vector2f position) 
    : damage(damage), attackSpeed(attackSpeed), position(position) {}

sf::Vector2f Tower::getPosition() const {
    return position;
}

int Tower::getDamage() const {
    return damage;
}

float Tower::getAttackSpeed() const {
    return attackSpeed;
}
