#ifndef NPC_H
#define NPC_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Map;  // Forward declaration of Map

class NPC {
protected:
    sf::CircleShape shape;  // Represents NPC as a circle
    int health;
    double speed;
    int damage;
    Vector2f position;
    int value;

public:
    NPC(int health, double speed, int damage, Vector2f position, int value);
    void move(Map& map, Vector2f playerPosition);
    virtual void takeDamage();
    void draw(RenderWindow& window);
    int getHealth() const;
    int getValue() const;
    ~NPC();
};

#endif
