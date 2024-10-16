#ifndef ELITE_H
#define ELITE_H

#include "NPC.h"
#include <random>

//Inhertance from NPC 
class Elite : public NPC {
    public:
        Elite(Vector2f pos); //constructor 
        virtual void takeDamage() override; //Allows different types of NPCS to take varying amounts of damage when attacked 
};

#endif