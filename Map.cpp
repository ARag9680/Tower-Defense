#include "Map.h"
#include "NPC.h"
#include "Towers.h"
#include "Player.h"

// Constructor
Map::Map(Vector2i tiles) : tiles(tiles) {
    grid = new bool*[tiles.y];
    for (int i = 0; i < tiles.y; i++) {
        grid[i] = new bool[tiles.x];
        for (int j = 0; j < tiles.x; j++) {
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
    for (int i = 0; i < tiles.y; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

int Map::getWidth(){ return this->tiles.x; };
int Map::getHeight(){ return this->tiles.y; };

void Map::loadMap(RenderWindow &window) {
    RectangleShape tile(Vector2f(20, 20));
    tile.setOutlineThickness(1);            
    tile.setOutlineColor(Color::Black);    

    for (int i = 0; i < tiles.y; i++) {
        for (int j = 0; j < tiles.x; j++) {
            tile.setFillColor(grid[i][j] ? Color::Red : Color::Green);
            tile.setPosition(j * 20, i * 20);
            window.draw(tile);
        }
    }
}

bool Map::canPlaceTower(Vector2i position) {
    if (position.x < 0 || position.x >= tiles.y || position.y < 0 || position.y >= tiles.x || !grid[position.x][position.y])
        return false;
    return true;
}

bool Map::isObstacle(Vector2i tile) {
    if (tile.x < 0 || tile.x >= tiles.x || tile.y < 0 || tile.y >= tiles.y)
        return false;
    return (grid[tile.x+1][tile.y+1] || grid[tile.x][tile.y+1] || grid[tile.x+1][tile.y]);
}

void Map::spawnNPC(NPC npc) {
    npcs.push_back(npc);
}

vector<NPC>& Map::getNPCs() {
    return npcs;
}

vector<Tower>& Map::getTowers() {
  return towers;
}

void Map::placeTower(Tower tower) {
    if (canPlaceTower(tower.getPosition())) {
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
        tower_it->draw(window);
        for (std::vector<NPC>::iterator npc_it = npcs.begin(); npc_it != npcs.end(); npc_it++){
            if (tower_it->isWithinRange(*npc_it)) {
                tower_it->drawAttackLine(window, *npc_it);
            }
        }
    }
}
