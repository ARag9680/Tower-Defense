#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    private:
        int health; 
        std::string name; 
        int currency; 
        int level; 
        //std::vector<Tower> towers; 

    public:
        Player(); 
        Player(int health, std::string name, int currency); 
        ~Player(); 

        int getHealth(); 
        int getCurrency(); 

        std::string getName(); 

        void buildTower(); 

        //bool isHit; 

        void sellTower(); 

        void takeDamage(int damage); 

        bool canAfford(); 

        void addMoney(int amount); 

}; 

#endif 