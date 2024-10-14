#ifndef TOWERS_H
#define TOWERS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>  // For distance calculation
#include "Player.h"


using namespace std;
using namespace sf;

class NPC;  // Forward declaration of NPC
class Player;

class Tower {
protected:
    RectangleShape shape;  // Represents Tower as a rectangle
    string type;
    int damage;
    float attackSpeed;
    int cost;
    Vector2i position;
    int range;
    float timeSinceLastAttack;

public:
    Tower(int damage, float attackSpeed, int cost, Vector2i position, int range);

    void dealDamage(NPC& npc, Player& player, float deltaTime);  // Now takes NPC and playerMoney
    int getCost();
    
    void placeOnMap(Vector2i newPosition);
    void draw(RenderWindow& window);
    
    // Check if the NPC is within range
    bool isWithinRange(NPC& npc);
    void drawAttackLine(RenderWindow& window, NPC& npc);  // Visual line
};

#endif /* TOWERS_H */
