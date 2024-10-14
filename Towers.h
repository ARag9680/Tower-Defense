#ifndef TOWERS_H
#define TOWERS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>  // For distance calculation
#include "NPC.h"

using namespace std;
using namespace sf;

// class NPC;  // Forward declaration of NPC

class Tower {
protected:
    RectangleShape shape;  // Represents Tower as a rectangle
    string type;
    int damage;
    float attackSpeed;
    int cost;
    Vector2i position;
    int range;

public:
    Tower(int damage, float attackSpeed, int cost, Vector2i position, int range);

    void dealDamage(NPC& npc, int playerMoney);  // Now takes NPC and playerMoney
    int getCost();
    Vector2i getPosition();
    
    void placeOnMap(Vector2i newPosition);
    void draw(RenderWindow& window);
    
    // Check if the NPC is within range
    bool isWithinRange(NPC& npc);
    void drawAttackLine(RenderWindow& window, NPC& npc);  // Visual line
};

#endif /* TOWERS_H */
