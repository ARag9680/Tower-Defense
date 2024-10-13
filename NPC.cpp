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

    // Calculate the potential next positions in both x and y
    Vector2f nextPos(newPos.x + step.x * speed, newPos.y + step.y * speed);

    // Get the current grid coordinates and next grid coordinates
    Vector2i grid(static_cast<int>(newPos.x / 20), static_cast<int>(newPos.y / 20));
    Vector2i nextGridRight(static_cast<int>((nextPos.x + shape.getRadius()) / 20), grid.y);
    Vector2i nextGridLeft(static_cast<int>((nextPos.x - shape.getRadius()) / 20), grid.y);
    Vector2i nextGridBottom(grid.x, static_cast<int>((nextPos.y + shape.getRadius()) / 20));
    Vector2i nextGridTop(grid.x, static_cast<int>((nextPos.y - shape.getRadius()) / 20));

    // Boundary check: Ensure grid coordinates are within bounds
    if (nextGridRight.x < 0 || nextGridLeft.x >= map.getWidth() || nextGridBottom.y < 0 || nextGridTop.y >= map.getHeight()) {
        return;  // Don't move if it would go out of bounds
    }

    // X-axis movement: Only move if there are no obstacles and within bounds
    bool canMoveX = (!map.isObstacle(Vector2i(nextGridRight.x, grid.y)) && !map.isObstacle(Vector2i(nextGridLeft.x, grid.y)));
    bool canMoveY = (!map.isObstacle(Vector2i(grid.x, nextGridBottom.y)) && !map.isObstacle(Vector2i(grid.x, nextGridTop.y)));

    // Now move in both axes, attempting both x and y, but respecting obstacles
    if (abs(delta.x) > abs(delta.y)) {
        if (canMoveX) {
            newPos.x = nextPos.x;
        } else if (canMoveY) {
            newPos.y = nextPos.y;
        }
    } else {
        if (canMoveY) {
            newPos.y = nextPos.y;
        } else if (canMoveX) {
            newPos.x = nextPos.x;
        }
    }

    // Update the NPC's position and shape
    position = newPos;
    shape.setPosition(position);
}

Vector2f NPC::getPosition(){
    return position;
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