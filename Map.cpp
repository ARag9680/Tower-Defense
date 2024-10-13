#include "Map.h"
#include "NPC.h"
#include "Tower.h"
#include "Player.h"

// Constructor
Map::Map(int h, int w) : height(h), width(w) {
    grid = new bool*[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new bool[width];
        for (int j = 0; j < width; j++) {
            grid[i][j] = false;  // Initialize all cells as paths (false = path, true = obstacle)
        }
    }

    grid[5][5] = true;
    grid[10][10] = true;
    grid[15][15] = true;
    grid[14][15] = true;
}

// Destructor
Map::~Map() {
    for (int i = 0; i < height; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

int Map::geWidth(){ return this->width; };
int Map::getHeight(){ return this->height; };

void Map::loadMap(RenderWindow &window) {
    RectangleShape tile(Vector2f(20, 20));
    tile.setOutlineThickness(1);            
    tile.setOutlineColor(Color::Black);    

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            tile.setFillColor(grid[i][j] ? Color::Red : Color::Green);
            tile.setPosition(j * 20, i * 20);
            window.draw(tile);
        }
    }
}

bool Map::canPlaceTower(int x, int y) {
    if (x < 0 || x >= height || y < 0 || y >= width || !grid[x][y])
        return false;
    return true;
}

bool Map::isObstacle(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height)
        return false;
    return (grid[x+1][y+1] || grid[x][y+1] || grid[x+1][y]);
}

void Map::spawnNPC(NPC npc) {
    npcs.push_back(npc);
}

vector<NPC>& Map::getNPCs() {
    return npcs;
}

void Map::placeTower(Tower tower, int x, int y) {
    if (canPlaceTower(x, y)) {
        towers.push_back(tower);
    }
}

void Map::checkDeadNPCs(Player& player) {
    std::vector<NPC>::iterator it = npcs.begin();
    while (it != npcs.end()) {
        if (it->getHealth() <= 0) {
            player.addMoney(it->getValue());
            it = npcs.erase(it);
        } else {
            ++it;
        }
    }
}

void Map::display(RenderWindow &window) {
    loadMap(window);
    for (std::vector<NPC>::iterator npc_it = npcs.begin(); npc_it != npcs.end(); ++npc_it) {
        npc_it->draw(window);
    }

    for (std::vector<Tower>::iterator tower_it = towers.begin(); tower_it != towers.end(); ++tower_it) {
        // Optionally display towers
    }
}
