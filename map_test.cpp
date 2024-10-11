#include <SFML/Graphics.hpp>
#include "Map.h"
#include "NPC.h"
#include "Tower.h"
#include "Player.h"
#include "PlayerController.h"

int main() {
    // Create an SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tower Defense");

    // Create a map object (e.g., 50x40 grid)
    Map map(50, 40);

    // Create some NPCs and Towers
    NPC npc1(100, 0.5f, 10, sf::Vector2f(0, 100));  // Example NPC with health 100, speed 0.5
    NPC npc2(150, 0.4f, 15, sf::Vector2f(0, 200));  // Another NPC at a different position
    Tower tower1(20, 1.0f, sf::Vector2f(200, 200)); // Example Tower with damage 20
    Tower tower2(30, 1.5f, sf::Vector2f(300, 300)); // Another Tower with different damage and position

    // Place the NPCs and Towers on the map
    map.spawnNPC(npc1);
    map.spawnNPC(npc2);
    map.placeTower(tower1, 10, 10);  // Example tower placement
    map.placeTower(tower2, 15, 15);  // Another tower placement

    PlayerController playerController("person"); //Create playerController
    Player playerTest(10, "playerName", 60); //Create player object

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        playerController.initializeInput(playerTest); //Allow player interaction

        // Clear the window
        window.clear();

        // Display the map, NPCs, and Towers
        map.display(window);

        // Display everything on the screen
        window.display();
    }

    return 0;
}
