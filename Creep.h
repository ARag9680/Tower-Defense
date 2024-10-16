#ifndef CREEP_H
#define CREEP_H

#include "NPC.h"

//Inhertance from NPC 
class Creep : public NPC {
    public:
        Creep(Vector2f pos); //constructor 
        virtual void takeDamage() override; //Allows different types of NPCS to take varying amounts of damage when attacked 
};

#endif