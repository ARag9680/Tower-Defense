#include "Player.h"
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
    if (canAfford() == true) {
        //call buildtower from map
        //currency = currency - tower price
    }
}


void Player::sellTower() {
    //remove tower from vector

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

