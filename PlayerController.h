#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <string>
#include "Player.h"
#include "Main_Menu.h"
using namespace std; 

class PlayerController {
    private:
        std::string name; 

        int waitForClick = 0; 
        
    public: 
        PlayerController(); //Default constructor 
        PlayerController(std::string name); //Player Controller Constructor, creates instance of player

        int getWaitForClick() {
            return waitForClick; 
        }

        int setWaitForClick(int waitForClick) {
            this->waitForClick = waitForClick; 
        }

        void initializeInput(Player player, Map& maps, RenderWindow& window); 
        void leftMousePressed(Player player, Map& maps, RenderWindow& window); //Detect left click
        void rightMousePressed(Player player, Map& maps, RenderWindow& window); //Detect right click

};

#endif