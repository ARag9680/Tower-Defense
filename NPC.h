// INCOMPLETE

#ifndef NPC_H
#define NPC_H

#include <SFML/Graphics.hpp>

class NPC {
private:
    sf::RectangleShape shape;  // Represents NPC as a rectangle
    int health;
    float speed;
    int damage;

public:
    NPC(int health, float speed, int damage, sf::Vector2f position);

    void move();  // Simulates movement of the NPC
    void draw(sf::RenderWindow& window);  // Draw the NPC on the screen
};

#endif
