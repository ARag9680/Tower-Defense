#ifndef CHAMPION_H
#define CHAMPION_H

#include "NPC.h"

//Inhertance from NPC 
class Champion : public NPC {
    private:
        float shieldHP; //Prevents some damage being applied to NPC 
    public:
        Champion(Vector2f pos, float shieldHP); //constructor 
        virtual void takeDamage() override; //Allows different types of NPCS to take varying amounts of damage when attacked 
};

#endif