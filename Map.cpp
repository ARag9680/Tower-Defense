#include "Map.h"
#include "NPC.h"
#include "Tower.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Map::Map(int h, int w) : height(h), width(w) {
    // Initialize the 2D array for the grid (false = path, true = obstacle)
    grid = new bool*[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new bool[width];
        for (int j = 0; j < width; j++) {
            grid[i][j] = false; // Default all tiles to "path" (false = path, true = obstacle)
        }
    }
}

Map::~Map() {
    // Clean up the dynamically allocated grid
    for (int i = 0; i < height; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Map::loadMap(sf::RenderWindow &window) {

    // Initialise map layout here (true = obstacle = placeable)

    grid[1][1] = true;  // Example obstacle
    grid[2][2] = true;  // Another example obstacle

    // Draw the map using SFML - draw grid and obstacles
    sf::RectangleShape tile(sf::Vector2f(20, 20));  // 20x20 pixel tiles
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j]) {
                tile.setFillColor(sf::Color::Red);  // Obstacles are red (can place towers)
            } else {
                tile.setFillColor(sf::Color::Green);  // Paths are green (cannot place towers)
            }
            tile.setPosition(j * 20, i * 20);  // Position based on grid indices
            window.draw(tile);
        }
    }
}

bool Map::canPlaceTower(int x, int y) {

    if (x < 0 || x >= height || y < 0 || y >= width || grid[x][y] == false) {
        return false;  // Cannot place on path tiles
    }
    for (int i = 0; i<towers.size(); i++){
        if (towers[i].getPosition().x == x || towers[i].getPosition().y == y){
            return false; // Cannot place on tiles that already have a tower
        }
    }
    return true;  // Can place on all other tiles
}

bool Map::isObstacle(int x, int y) {
    // Return whether the tile at (x, y) is an obstacle
    if (x < 0 || x >= height || y < 0 || y >= width) {
        return true;  // Out of bounds
    }
    return grid[x][y];  // True if obstacle, false if path
}

void Map::spawnNPC(const NPC& npc) {
    // Add the NPC to the NPC vector
    npcs.push_back(npc);
}

void Map::placeTower(const Tower& tower, int x, int y) {
    if (canPlaceTower(x, y)) {
        // Place the tower and add it to the tower vector
        towers.push_back(tower);
    } else {
        std::cout << "Cannot place tower at (" << x << ", " << y << ")." << std::endl;
    }
}

void Map::display(sf::RenderWindow &window) {
    // Draw the map
    loadMap(window);

    // Draw NPCs
    for (int i = 0; i < npcs.size(); i++) {
        npcs[i].move();      // Move the NPC (simple movement logic)
        npcs[i].draw(window);  // Draw the NPC on the screen
    }

    // Draw Towers
    for (int i = 0; i < towers.size(); i++) {
        // Draw each tower as a circle on the grid at the tower's position
        sf::CircleShape towerShape(10);  // Tower is a circle with radius 10
        towerShape.setFillColor(sf::Color::Yellow);  // Color the tower yellow
        towerShape.setPosition(towers[i].getPosition());  // Set the position of the tower

        window.draw(towerShape);  // Draw the tower shape on the window
    }
}