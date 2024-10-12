#ifndef ELITE_H
#define ELITE_H

#include "NPC.h"
#include <random>

class Elite : public NPC {
    public:
        Elite(Vector2f pos);
        virtual void takeDamage() override;
};

#endif