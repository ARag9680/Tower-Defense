#include "Player.h"
#include "Map.h"
#include "Tower.h"
#include <iostream>

Player::Player() {}

Player::Player(int health, std::string name, int currency) : health(health), name(name), currency(currency) {}

std::string Player::getName() {
    return name; 
}

int Player::getHealth() {
    return health; 
}

int Player::getCurrency() {
    return currency;    
}

Player::~Player() {}

void Player::buildTower() {
    Tower* tower = new Tower(20, 1.0f, sf::Vector2f(200, 200)); // Example tower

    if (tower != nullptr) {
        maps->placeTower(*tower, 5, 5);  // Placeholder for tower placement
        //currently causes seg fault
    }
}

void Player::sellTower() {
    // Logic for selling tower
}

void Player::takeDamage(int damage) {
    health = health - damage; 
}

bool Player::canAfford() {
    if (getCurrency() > 0) {
        return true;
    }
    
    return false; 
}

void Player::addMoney(int amount) {
    currency = currency + amount; 
    std::cout << "Currency: " << currency << std::endl; 
}
