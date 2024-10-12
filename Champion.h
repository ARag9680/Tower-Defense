#ifndef CHAMPION_H
#define CHAMPION_H

#include "NPC.h"

class Champion : public NPC {
    private:
        float shieldHP;
    public:
        Champion(Vector2f pos, float shieldHP);
        virtual void takeDamage() override;
};

#endif