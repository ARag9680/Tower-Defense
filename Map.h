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
    int height;
    int width;
    bool** grid;  // 2D dynamically allocated grid
    vector<NPC> npcs;
    vector<Tower> towers;
    Vector2f player_spawn;

public:
    Map(int h, int w);
    ~Map();
    vector<NPC>& getNPCs();
    int geWidth();
    int getHeight();
    void loadMap(RenderWindow &window);
    bool canPlaceTower(int x, int y);
    bool isObstacle(int x, int y);
    void spawnNPC(NPC npc);
    void placeTower(Tower tower, int x, int y);
    void display(RenderWindow &window);
    void checkDeadNPCs(Player& player);  // Use Player reference for currency handling
};

#endif
