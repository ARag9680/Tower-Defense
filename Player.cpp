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

<<<<<<< HEAD
// void Player::buildTower() {
//         Tower* tower = new Tower(20, 1.0f, sf::Vector2f(200, 200)); // test tower to pass to function 
=======
void Player::buildTower(Vector2i position, Map& maps) {
        Tower tower(1,10,1,Vector2i(120, 120),10000); //Test tower object 
>>>>>>> refs/remotes/origin/Alt_Test

//         if (tower != nullptr) {
//             maps->placeTower(*tower, Vector2f); 
//             //currently causes seg fault
//         }

<<<<<<< HEAD
//         //currency = currency - tower price    
// }
=======
        //cout << "Function Called Successfuly" << endl; 

        //currency = currency - tower price    
}
>>>>>>> refs/remotes/origin/Alt_Test

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

