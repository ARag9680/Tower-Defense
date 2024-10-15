#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

// Forward declarations to avoid #include cycles
class NPC;
class Tower;
class Player;

using namespace sf;
using namespace std;

class Map {
private:
    Vector2i tiles;
    int** grid;  // 2D dynamically allocated grid
    vector<NPC> npcs;
    vector<Tower> towers;
    Vector2f player_spawn;
    float deltaTime;

public:
    Map(Vector2i tiles);
    ~Map();
    vector<NPC>& getNPCs();
    int getWidth();
    int getHeight();
    void loadMap(RenderWindow &window, Vector2i mousePos);
    bool canPlaceTower(Vector2i position);
    bool isObstacle(Vector2i tile);
    void spawnNPC(NPC npc);
    void placeTower(Tower& tower, Vector2i position);
    void display(RenderWindow &window, Player& player, Clock& clock, Vector2i mousePos, Event mouseButtonPressed);
    void checkDeadNPCs(Player& player);  // Use Player reference for currency handling
    void handleInput(Player& player, Vector2i mousePos, Event mouseButtonPressed);
    void readGridFromFile(const std::string& filename);
};

#endif
