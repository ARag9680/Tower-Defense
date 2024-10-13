#ifndef TOWERS_H
#define TOWERS_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include <string>
//#include "NPC.h"
using namespace std;
using namespace sf;

class Tower {
protected:
    RectangleShape shape;  // Represents NPC as a rectangle
    string type;
    int damage;
    float attackSpeed;
    int cost;
    Vector2i position;

public:
    Tower(int health, float attackSpeed, int damage, int cost, Vector2i position);
    void dealDamage(NPC Npc);
    int getCost;
    void placeOnMap(Vector2i);
    void draw(sf::RenderWindow& window);  // Draw the NPC on the screen
};

#endif /* TOWERS_H */
