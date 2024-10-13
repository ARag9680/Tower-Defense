#include "Towers.h"
#include "NPC.h"  // Include NPC header for reference

Tower::Tower(int damage, float attackSpeed, int cost, Vector2i position, int range)
: damage(damage), attackSpeed(attackSpeed), cost(cost), position(position), range(range) {
    shape.setPosition(static_cast<float>(position.x), static_cast<float>(position.y));
    shape.setSize(Vector2f(20.0f, 20.0f));  // Arbitrary size for the tower
    shape.setFillColor(Color::Blue);
}


// Check if NPC is within range
bool Tower::isWithinRange(NPC& npc) {
    Vector2f npcPos = npc.getPosition();
    float distance = sqrt(pow(position.x - npcPos.x, 2) + pow(position.y - npcPos.y, 2));
    return distance <= range;
}

int Tower::getCost(){ 
    return cost; 
}

// Draw a line from the tower to the NPC (for visual representation of attack)
void Tower::drawAttackLine(RenderWindow& window, NPC& npc) {
    if (isWithinRange(npc)) {
        VertexArray line(Lines, 2);
        line[0].position = Vector2f(static_cast<float>(position.x), static_cast<float>(position.y));
        line[0].color = Color::Red;
        line[1].position = npc.getPosition(); 
        line[1].color = Color::Red;
        window.draw(line);
    }
}
void Tower::placeOnMap(Vector2i newPosition) {
        position = newPosition;
        shape.setPosition(static_cast<float>(position.x), static_cast<float>(position.y));
        }

// Deal damage to NPC and increase player's money if the NPC's health reaches zero
void Tower::dealDamage(NPC& npc, int& playerMoney) {
    if (isWithinRange(npc)) {
        npc.takeDamage();
        if (npc.getHealth() <= 0) {
            playerMoney += npc.getValue();
        }
    }
}

void Tower::draw(RenderWindow& window) {
        window.draw(shape);
}
