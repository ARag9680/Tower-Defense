#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Map.h"
#include "Towers.h"
using namespace std; 

class Player {
    private:
        int health; 
        std::string name; 
        int currency; 
        //std::vector<Tower> towers; 
        Map *maps; 
        Vector2f playerPosition;
    public:
        Player();  //Default constuctor 
        Player(int health, std::string name, int currency);  //Player constructor - creates player with certian health, name and currency 
        ~Player(); //Default deconstructor 

        //Get value of health, currency and name
        int getHealth() const; 
        int getCurrency() const; 
        string getName(); 

        void buildTower(Vector2i position); 
        
        Vector2f getPlayerPosition();
        void setPlayerPosition(Vector2f Spawn);

        void sellTower(); 

        void takeDamage(int damage); 

        bool canAfford(); 

        void addMoney(int amount); 

}; 

#endif 