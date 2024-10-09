#include "PlayerController.h"
#include "Player.h"
#include <SFML/Window/Mouse.hpp>
#include <iostream>

PlayerController::PlayerController() {}; 

PlayerController::PlayerController(std::string name) : name(name) {}; 

void PlayerController::initializePlayer() {
    Player playerTest(10, "playerName", 60); 
    std::cout << "Player Created!" << std::endl; 
}

void PlayerController::leftMousePressed() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::cout << "Mouse Pressed!" << std::endl; 
    } 
}

void PlayerController::initializeInput() {

}

        
void PlayerController::rightMousePressed() {}; 