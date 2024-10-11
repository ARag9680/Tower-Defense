#include "PlayerController.h"
#include "Player.h"
#include <SFML/Window/Mouse.hpp>
#include <iostream>

using namespace sf; 

PlayerController::PlayerController() {}; 

PlayerController::PlayerController(std::string name) : name(name) {}; 

void PlayerController::initializeInput(Player player) { 
    leftMousePressed(player); 
    rightMousePressed(player); 
}

void PlayerController::leftMousePressed(Player player) {
    setWaitForClick(1); //can be set to 0 to not allow clicking
    if (Mouse::isButtonPressed(sf::Mouse::Left) && getWaitForClick() == 1) {
        player.buildTower(); 

        cout << "Mouse Pressed!" << endl;
        
    } 
}
        
void PlayerController::rightMousePressed(Player player) {
    setWaitForClick(1); //can be set to 0 to not allow clicking
    if (Mouse::isButtonPressed(sf::Mouse::Right) && getWaitForClick() == 1) {
        player.sellTower(); 

        cout << "Mouse 2 Pressed!" << endl;
        
    } 
}