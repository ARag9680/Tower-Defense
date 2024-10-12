#include <SFML/Graphics.hpp>
#include "Map.h"
#include "NPC.h"
#include "Tower.h"
#include "Player.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(400,400), "Tower Defense");

    Map gameMap(20, 20);  // A 20x20 map
    Player player(100, "Player1", 100);  // Player with health and currency

    // Fixed player position (could be the bottom right corner)
    Vector2f playerPosition(400,400);  // Bottom-right of the window for example

    // Create NPC at position (0, 0)
    NPC enemy(100, 0.5, 10, Vector2f(0, 0), 50);
    gameMap.spawnNPC(enemy);

    // Game loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Clear the window for new frame
        window.clear();

        // Move NPCs towards the player position using a non-const iterator
        for (std::vector<NPC>::iterator npc_it = gameMap.getNPCs().begin(); npc_it != gameMap.getNPCs().end(); ++npc_it) {
            npc_it->move(gameMap, playerPosition);
        }

        // Display the map and NPCs
        gameMap.display(window);

        // Display the new frame
        window.display();
    }

    return 0;
}