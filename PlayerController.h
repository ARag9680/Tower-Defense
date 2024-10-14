#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <string>
#include "Player.h"
using namespace std; 

class PlayerController {
    private:
        std::string name; 

        int waitForClick = 0; 
        
    public: 
        PlayerController(); //Default constructor 
        PlayerController(std::string name); //Player Controller Constructor, creates instance of player

        int getWaitForClick();

        void setWaitForClick(int waitForClick);

        void initializeInput(Player player); 
        void leftMousePressed(Player player); //Detect left click
        void rightMousePressed(Player player); //Detect right click

};

#endif