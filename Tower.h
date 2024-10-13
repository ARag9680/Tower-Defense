#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>

class NPC;  // Forward declaration of NPC (instead of including the full header)

using namespace sf;

class Tower {
private:
    Vector2f position;
    int damage;
    float attackSpeed;

public:
    Tower(int damage, float attackSpeed, Vector2f position);
    Vector2f getPosition() const;
    int getDamage() const;
    float getAttackSpeed() const;
    void attackNPC(NPC &npc);  // NPC is now forward-declared
};

#endif
