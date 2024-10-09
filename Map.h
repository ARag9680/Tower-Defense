#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

class NPC;
class Tower;

class Map {
private:
    int height;
    int width;
    bool** grid;                      // 2D array of booleans for map tiles (true = obstacle, false = path)
    std::vector<NPC> npcs;            // Vector of NPCs on the map
    std::vector<Tower> towers;        // Vector of Towers placed on the map

public:
    Map(int h, int w);
    ~Map();                           // Destructor to free the dynamically allocated grid

    void loadMap(RenderWindow &window);  // Loads the map using SFML
    bool canPlaceTower(int x, int y);        // Checks if a tower can be placed at (x, y)
    bool isObstacle(int x, int y);           // Checks if (x, y) is an obstacle
    void spawnNPC(const NPC& npc);           // Adds an NPC to the map
    void placeTower(const Tower& tower, int x, int y); // Places a tower at (x, y)
    void display(RenderWindow &window);  // Displays the map, NPCs, and Towers using SFML
};

#endif
