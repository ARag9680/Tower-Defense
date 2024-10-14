#include "Player.h"
#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include "Map.h"
#include "Towers.h"

using namespace std; 

Player::Player() {}

Player::Player(int health, std::string name, int currency) : health(health), name(name), currency(currency) {}

std::string Player::getName() {
    return name; 
}

int Player::getHealth() const {
    return health; 
}

int Player::getCurrency() const {
    return currency;    
}

sf::Vector2f Player::getPlayerPosition(){
    return playerPosition;
}

void Player::setPlayerPosition(Vector2f Spawn){
    this->playerPosition = Spawn;
}

Player::~Player() {}

void Player::buildTower(Vector2i position) {

    std::cout << "Attempting to build tower at: " << position.x << ", " << position.y << std::endl;


    Tower* tower = new Tower(20, 1.0f, 50, position, 50); // test tower to pass to function 
    cout << "Tower built" << endl;
    if (tower != nullptr) {
        maps->placeTower(*tower); 
        //currently causes seg fault
    }

    currency = currency - tower->getCost();
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

