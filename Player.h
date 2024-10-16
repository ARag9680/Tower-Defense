#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Towers.h"
using namespace std;
using namespace sf; 

class Map; // forward declaration of Map

class Player {
    private:
        int health; 
        std::string name; 
        int currency; 
        //std::vector<Tower> towers; 
        Map* maps; //Reference to map
        Vector2f playerPosition;
    public:
        Player();  //Default constuctor 
        Player(int health, std::string name, int currency);  //Player constructor - creates player with certian health, name and currency 
        ~Player(); //Default deconstructor 

        //Get value of health, currency and name
        int getHealth(); 
        int getCurrency(); 
        string getName();

        void drawPlayerIndicator(sf::RenderWindow* win);
        
        Vector2f getPlayerPosition();
        void setPlayerPosition(Vector2f Spawn);
        void setHealth( int health);

        void sellTower(); 

        void takeDamage(int damage); 

        bool canAfford(); 

        void addMoney(int amount); 

}; 

#endif