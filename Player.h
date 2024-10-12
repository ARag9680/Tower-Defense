#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Map;  // Forward declaration of Map

using namespace std; 

class Player {
    private:
        int health; 
        std::string name; 
        int currency; 
        Map *maps; 

    public:
        Player();  // Default constructor 
        Player(int health, std::string name, int currency);  // Player constructor
        ~Player(); // Destructor

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
