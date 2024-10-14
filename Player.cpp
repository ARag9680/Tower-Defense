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

int Player::getHealth() {
    return health; 
}

int Player::getCurrency() {
    return currency;    
}

sf::Vector2f Player::getPlayerPosition(){
    return playerPosition;
}

void Player::setPlayerPosition(Vector2f Spawn){
    this->playerPosition = Spawn;
}

Player::~Player() {}

/*
void Player::buildTower() {
    Tower tower(1,10,1,Vector2i(120, 120),10000); //Test tower object 

    maps.placeTower(tower, Vector2i(10, 10)); //Call placeTower from Map, adds to tower vector 

    cout << "Function Called Successfuly" << endl; 

    currency = currency - tower price   
}
*/

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

