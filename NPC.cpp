#include "NPC.h"
#include "Map.h"
#include <iostream>


NPC::NPC(int h, double s, int d, Vector2f pos, int val) 
    : health(h), speed(s), damage(d), position(pos), value(val) {
    shape.setRadius(8.0f);  // Example radius
    shape.setFillColor(Color::Blue);  // Set the fill color
    shape.setPosition(position);  // Set the initial position
}

void NPC::move(Map& map, Vector2f playerPosition) {
    Vector2f newPos = position;

    // Calculate direction towards the player
    Vector2f delta = playerPosition - newPos;

    // Determine the movement step in x and y directions
    Vector2i step((delta.x > 0) ? 1 : -1, (delta.y > 0) ? 1 : -1);

    // Calculate potential next positions in both axes
    Vector2f nextPosX(newPos.x + step.x * speed, newPos.y);
    Vector2f nextPosY(newPos.x, newPos.y + step.y * speed);

    // Get the grid coordinates for the current and next positions
    Vector2i currentGrid(static_cast<int>(newPos.x / 20), static_cast<int>(newPos.y / 20));
    Vector2i nextGridX(static_cast<int>(nextPosX.x / 20), currentGrid.y);
    Vector2i nextGridY(currentGrid.x, static_cast<int>(nextPosY.y / 20));

    // Check for obstacles in x and y directions
    bool canMoveX = !map.isObstacle(nextGridX);
    bool canMoveY = !map.isObstacle(nextGridY);

    // Prioritize movement in the direction with fewer obstacles
    if (canMoveX) {
        newPos.x = nextPosX.x;
    } else if (canMoveY) {
        newPos.y = nextPosY.y;
    }

    // Update NPC's position and shape
    position = newPos;
    shape.setPosition(position);
}


Vector2f NPC::getPosition(){
    return position;
}

void NPC::dealDamage(Player* player) {
    player->setHealth(player->getHealth() - this->damage);
}

void NPC::takeDamage() {
    health -= 1;
    if (health <= 0) {
        health = 0;
    }
    cout<< "NPC took damage" <<endl;
}

void NPC::draw(RenderWindow& window) {
    window.draw(shape);
}

int NPC::getHealth() const {
    return health;
}

int NPC::getValue() const {
    return value;
}

NPC::~NPC() {}