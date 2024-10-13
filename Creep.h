#ifndef CREEP_H
#define CREEP_H

#include "NPC.h"


class Creep : public NPC {
    public:
        Creep(Vector2f pos);
        virtual void takeDamage() override;
};

#endif