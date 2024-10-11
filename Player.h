#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Map.h"
#include "Tower.h"
using namespace std; 

class Player {
    private:
        int health; 
        std::string name; 
        int currency; 
        //std::vector<Tower> towers; 
        Map *maps; 

    public:
        Player();  //Default constuctor 
        Player(int health, std::string name, int currency);  //Player constructor - creates player with certian health, name and currency 
        ~Player(); //Default deconstructor 

        //Get value of health, currency and name
        int getHealth(); 
        int getCurrency(); 
        string getName(); 

        void buildTower(); 

        void sellTower(); 

        void takeDamage(int damage); 

        bool canAfford(); 

        void addMoney(int amount); 

}; 

#endif 