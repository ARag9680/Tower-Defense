#include "PlayerController.h"
#include "Player.h"
#include <SFML/Window/Mouse.hpp>
#include <iostream>

using namespace sf; 

PlayerController::PlayerController() {}; 

PlayerController::PlayerController(std::string name) : name(name) {}; 

/* Logic implemented in map file 
void PlayerController::initializeInput(Player player, Map& maps, RenderWindow& window) { 
    leftMousePressed(player, maps, window); 
    rightMousePressed(player, maps, window); 
}

void PlayerController::leftMousePressed(Player player, Map& maps, RenderWindow& window) {
    setWaitForClick(1); //can be set to 0 to not allow clicking
    sf::Event event; 

    while (window.pollEvent(event)) {
        if ((event.type == sf::Event::MouseButtonPressed) && getWaitForClick() == 1) {
            player.buildTower(Mouse::getPosition() - Vector2i(100,100),maps); //Calls buildtower from player, passes map as reference 
            cout << "Mouse Pressed!" << endl;
        } 
    }
    
}
        
void PlayerController::rightMousePressed(Player player, Map& maps, RenderWindow& window) {
    setWaitForClick(1); //can be set to 0 to not allow clicking

    if (Mouse::isButtonPressed(sf::Mouse::Right) && getWaitForClick() == 1) {
        //player.sellTower(); 

        cout << "Mouse 2 Pressed!" << endl;
        
    } 
}
*/