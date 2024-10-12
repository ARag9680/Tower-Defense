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
    float deltaX = playerPosition.x - newPos.x;
    float deltaY = playerPosition.y - newPos.y;

    // Determine the movement step in x and y directions
    int stepX = (deltaX > 0) ? 1 : -1;
    int stepY = (deltaY > 0) ? 1 : -1;

    // Calculate the potential next positions in both x and y
    float nextX = newPos.x + stepX * speed;
    float nextY = newPos.y + stepY * speed;

    // Get the current grid coordinates and next grid coordinates
    int gridX = static_cast<int>(newPos.x / 20);
    int gridY = static_cast<int>(newPos.y / 20);
    int nextGridXRight = static_cast<int>((nextX + shape.getRadius()) / 20);
    int nextGridXLeft = static_cast<int>((nextX - shape.getRadius()) / 20);
    int nextGridYBottom = static_cast<int>((nextY + shape.getRadius()) / 20);
    int nextGridYTop = static_cast<int>((nextY - shape.getRadius()) / 20);

    // Boundary check: Ensure grid coordinates are within bounds
    if (nextGridXRight < 0 || nextGridXLeft >= map.geWidth() || nextGridYBottom < 0 || nextGridYTop >= map.getHeight()) {
        return;  // Don't move if it would go out of bounds
    }

    // X-axis movement: Only move if there are no obstacles and within bounds
    bool canMoveX = (!map.isObstacle(nextGridXRight, gridY) && !map.isObstacle(nextGridXLeft, gridY));
    bool canMoveY = (!map.isObstacle(gridX, nextGridYBottom) && !map.isObstacle(gridX, nextGridYTop));

    // Now move in both axes, attempting both x and y, but respecting obstacles
    if (abs(deltaX) > abs(deltaY)) {
        if (canMoveX) {
            newPos.x = nextX;
        } else if (canMoveY) {
            newPos.y = nextY;
        }
    } else {
        if (canMoveY) {
            newPos.y = nextY;
        } else if (canMoveX) {
            newPos.x = nextX;
        }
    }

    // Update the NPC's position and shape
    position = newPos;
    shape.setPosition(position);
}

void NPC::takeDamage() {
    health -= 1;
    if (health <= 0) {
        health = 0;
    }
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