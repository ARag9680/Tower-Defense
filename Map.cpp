#include "Map.h"
#include "NPC.h"
#include "Towers.h"
#include "Player.h"

#include <fstream>
#include <sstream>
#include <iostream>

enum TileState {
    PATH = 0,        // Path where NPCs walk
    OBSTACLE = 1,    // Obstacle where towers can be placed
    OCCUPIED = 2     // A tower has already been placed on this tile
};

// Constructor
Map::Map(Vector2i tiles) : tiles(tiles) {
    grid = new int*[tiles.y];
    for (int i = 0; i < tiles.y; i++) {
        grid[i] = new int[tiles.x];
        for (int j = 0; j < tiles.x; j++) {
            grid[i][j] = PATH;  // Initialize all cells as paths
        }
    }
    grid[5][5] = OBSTACLE;  // Example obstacles
    grid[10][10] = OBSTACLE;
    grid[15][15] = OBSTACLE;
    grid[14][15] = OBSTACLE;

    Creep example_creep(Vector2f(0,0));
    Elite example_elite(Vector2f(0, 30));
    Champion example_champion(Vector2f(50, 0), 10);
    Creep example_creep1(Vector2f(0,10));
    Elite example_elite1(Vector2f(0, 20));
    Champion example_champion1(Vector2f(40, 0), 10);
    cout << "Enemies Initalized"<< endl;
    this->spawnNPC(example_creep);
    this->spawnNPC(example_elite);
    this->spawnNPC(example_champion);
    this->spawnNPC(example_creep1);
    this->spawnNPC(example_elite1);
    this->spawnNPC(example_champion1);
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

void Map::loadMap(RenderWindow &window, Vector2i mousePos) {
    RectangleShape tile(Vector2f(20, 20));
    tile.setOutlineThickness(1);
    tile.setOutlineColor(Color::Black);

    for (int i = 0; i < tiles.y; i++) {
        for (int j = 0; j < tiles.x; j++) {
            Vector2f tilePos(j * 20, i * 20);
            tile.setPosition(tilePos);

            // Check if mouse is hovering over this tile
            if (tile.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                // Check if it's an obstacle
                if (grid[i][j]) {
                    tile.setFillColor(Color::Cyan); // Indicate tower can be placed here (hover)
                } else {
                    tile.setFillColor(Color::Yellow); // Can't place tower here (hover)
                }
            } else {
                // Default color based on obstacle or not
                tile.setFillColor(grid[i][j] ? Color::Red : Color::Green);
            }
            
            window.draw(tile);
        }
    }
}

bool Map::canPlaceTower(Vector2i position) {
    if (position.x < 0 || position.x >= tiles.x || position.y < 0 || position.y >= tiles.y)
        return false;  // Out of bounds
    // Check if the tile is an obstacle and not already occupied
    return (grid[position.y][position.x] == OBSTACLE);
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

void Map::placeTower(Tower& tower, Vector2i position) {
    if (canPlaceTower(position)) {
        towers.push_back(tower);
        grid[position.y][position.x] = OCCUPIED;  // Mark the tile as occupied
        std::cout << "Tower placed at: " << position.x << ", " << position.y << endl;
    } else {
        std::cout << "Failed to place tower" << endl;
    }
}

void Map::checkDeadNPCs(Player& player) {
    vector<NPC>::iterator it = npcs.begin();
    while (it != npcs.end()) {
        if (it->getHealth() <= 0) {
            player.addMoney(it->getValue());
            it = npcs.erase(it);
        } else {
            ++it;
        }
    }
}

void Map::display(RenderWindow &window, Player& player, Clock& clock, Vector2i mousePos, Event mouseButtonPressed) {
    loadMap(window, mousePos);
    handleInput(player, mousePos, mouseButtonPressed);
    player.drawPlayerIndicator(&window);

    for (vector<NPC>::iterator npc_it = npcs.begin(); npc_it != npcs.end();) {
        if (npc_it->getHealth() <= 0) {
            // Remove NPC from the vector if health is 0 or less
            npc_it = npcs.erase(npc_it);  // erase returns the next iterator
        } else {
            // Draw the NPC if still alive
            npc_it->draw(window);
            ++npc_it;
        }
    }
    deltaTime = clock.restart().asSeconds();
    for (vector<Tower>::iterator tower_it = towers.begin(); tower_it != towers.end(); ++tower_it) {
        tower_it->draw(window);
        for (vector<NPC>::iterator npc_it = npcs.begin(); npc_it != npcs.end(); npc_it++){
            tower_it->drawAttackLine(window, *npc_it);// Optionally display towers
            tower_it->dealDamage(*npc_it, player, deltaTime);
        }
    }

    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {  // Load font for rendering text
        std::cerr << "Error loading font" << std::endl;
        return;
    }

    sf::Text healthText;
    healthText.setFont(font);
    healthText.setString("Health: " + std::to_string(player.getHealth()));
    healthText.setCharacterSize(20);
    healthText.setFillColor(sf::Color::Black);
    healthText.setPosition(10, 410);  // Position below the grid

    // Create a text object for player currency
    sf::Text currencyText;
    currencyText.setFont(font);
    currencyText.setString("Currency: " + std::to_string(player.getCurrency()));
    currencyText.setCharacterSize(20);
    currencyText.setFillColor(sf::Color::Black);
    currencyText.setPosition(10, 440);  // Position below the health text

    // Draw the health and currency texts
    window.draw(healthText);
    window.draw(currencyText);

}

void Map::handleInput(Player& player, Vector2i mousePos, Event mouseButtonPressed) {
    if (mouseButtonPressed.type == Event::MouseButtonPressed && mouseButtonPressed.mouseButton.button == Mouse::Left) {
        // Check if we can place a tower at this position and the player can afford it
        Vector2i gridPos(mousePos.x / 20, mousePos.y / 20);
        if (canPlaceTower(gridPos) && player.canAfford()) {
            
            Vector2i towerPos(gridPos.x * 20, gridPos.y * 20);
            Tower tower(1,10,1,towerPos,10000);
            
            placeTower(tower, gridPos);
            player.addMoney(-tower.getCost()); // Subtract 1 currency to build tower
            std::cout<< "tower placed at: " << mousePos.x << "." << mousePos.y <<endl;
        }
        else{
            std::cout<< "failed to place tower" <<endl;
        }
    }
}

void Map::readGridFromFile(const std::string& filename) {
    // Reads map data from csv file of 0s,1s,2s (PATH, OBSTACLE, OCCUPIED)
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string line = "";
    int row = 0;

    // Read the file line by line
    while (std::getline(file, line) && row < getHeight()) {
        std::stringstream ss(line);
        std::string cell;
        int col = 0;

        // Parse each cell (0, 1, 2) and populate the grid
        while (std::getline(ss, cell, ',') && col < getWidth()) {
            std::getline(ss, cell, ',');
            int value = std::stoi(cell);  // Convert string to int

            switch (value) {
                case 0:
                    grid[row][col] = PATH;
                    break;
                case 1:
                    grid[row][col] = OBSTACLE;
                    break;
                case 2:
                    grid[row][col] = OCCUPIED;
                    break;
                default:
                    std::cerr << "Invalid value in CSV: " << value << std::endl;
                    break;
            }
            col++;
        }
        row++;
    }

    file.close();
}
