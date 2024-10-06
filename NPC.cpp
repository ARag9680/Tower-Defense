// INCOMPLETE

#include "NPC.h"

NPC::NPC(int health, float speed, int damage, sf::Vector2f position) 
    : health(health), speed(speed), damage(damage) {
    shape.setSize(sf::Vector2f(20, 20));  // 20x20 pixels
    shape.setFillColor(sf::Color::Blue);  // NPCs are blue
    shape.setPosition(position);  // Set initial position
}

void NPC::move() {
    // Simulate simple movement (move 1 unit right for demonstration)
    shape.move(speed, 0);
}

void NPC::draw(sf::RenderWindow& window) {
    window.draw(shape);  // Draw the NPC on the window
}
