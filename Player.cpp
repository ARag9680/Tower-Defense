#include "Player.h"
#include <iostream>
#include <SFML/Window/Mouse.hpp>
//include "Main_Menu.h"
//#include <SFML/Graphics.hpp>
#include "Map.h"

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
        //map->placeTower(tower1, 10, 10); 

       


        //call buildtower from map
        //placeTower(); 
        //add to towers 
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

