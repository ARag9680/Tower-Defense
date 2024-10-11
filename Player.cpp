#include "Player.h"
#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include "Map.h"
#include "Tower.h"

using namespace std; 

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
        Tower* tower = new Tower(20, 1.0f, sf::Vector2f(200, 200)); // test tower to pass to function 

        if (tower != nullptr) {
            maps->placeTower(*tower, 5, 5); 
            //currently causes seg fault
        }

        //currency = currency - tower price    
}

void Player::sellTower() {
    //remove tower from vector
    //check removed tower
    //use switch to determime tower type and add currency as required
}



void Player::takeDamage(int damage) {
    //if (isHit == true) {
    health = health - damage; 
    //}
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

