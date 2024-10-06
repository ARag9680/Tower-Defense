#include "Map.h"
#include <SFML/Window.hpp>
#include <iostream>

#include <vector>

Map::Map(){
    this->height = 48;
    this->width = 27;
    this->grid = new bool*[this->height];
    for (int i=0; i<this->height; i++){
        grid[i] = new bool[this->width];
    }
}

Map::~Map() {
    // Clean up the dynamically allocated grid
    for (int i = 0; i < height; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Map::loadMap() {

    // Create window
    sf::Window window(sf::VideoMode::getDesktopMode(), "Tower Defense");
    window.setPosition(sf::Vector2i(0,0));

    while (window.isOpen()){ // Event handler
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    }


}

bool Map::canPlaceTower(int x, int y) { 
    if (!(this->isObstacle(x, y))){return false; } // if the tile is a path tile, a tower cannot be placed
    for (int i = 0; i<towers.size(); i++){
        if ((x == towers[i].getPosition().first) && (y == towers[i].getPosition().second)){
            return false;
        }
    }
    return true;
}

// returns true if grid[x][y] is false (is an obstacle) and returns false if grid[x][y] is true (is a path)
bool Map::isObstacle(int x, int y){
    return !(this->grid[x][y]);    
}

void Map::spawnNPC(NPC npc){
    npcs.push_back(npc); // adds the new NPC to the vector of npcs
}

void Map::placeTower(Tower tower){
    towers.push_back(tower); // adds the new tower to the vector of towers
}

void Map::display(){

    for (int i = 0; i < npcs.size(); i++){
        NPC npc_disp = npcs[i];
    }
    for (int i = 0; i < towers.size(); i++){
        Tower tower_disp = towers[i];
    }
}