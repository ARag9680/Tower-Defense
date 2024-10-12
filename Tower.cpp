#include "Tower.h"
#include "NPC.h"

Tower::Tower(int dmg, float atkSpeed, Vector2f pos) 
    : damage(dmg), attackSpeed(atkSpeed), position(pos) {}

Vector2f Tower::getPosition() const {
    return position;
}

int Tower::getDamage() const {
    return damage;
}

float Tower::getAttackSpeed() const {
    return attackSpeed;
}

void Tower::attackNPC(NPC &npc) {
    npc.takeDamage();
}