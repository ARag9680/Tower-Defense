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
    int health; //NPC health
    double speed; //NPC speed 
    int damage; //Damage NPC does to towers
    Vector2f position; //Position on map 
    int value;

public:
    //NPC constructor - create NPC with health, speed, damage, position and value 
    NPC(int health, double speed, int damage, Vector2f position, int value);
    void move(Map& map, Vector2f playerPosition);
    virtual void takeDamage();
    //method to Draw/show NPC on map
    void draw(RenderWindow& window);
    int getHealth() const;
    int getValue() const;
    Vector2f getPosition();
    ~NPC();
};

#endif
