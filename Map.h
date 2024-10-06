#ifndef MAP_H
#define MAP_H

#include "NPC.h"
#include "Tower.h"
#include <SFML/Window.hpp>

#include <vector>
using namespace std;

class Map {
    private:
        // Dimensions of map
        int height;
        int width;
        bool** grid; // 2D array of booleans - represents whether each tile is a path (true) or obstacle (false)
        vector<NPC> npcs; // Vector storing all NPC objects
        vector<Tower> towers; // Vector storing all Tower objects
    public:
        Map();
        ~Map();
        void loadMap();
		bool canPlaceTower(int x, int y);
		bool isObstacle(int x, int y);
		void spawnNPC(NPC npc);
		void placeTower(Tower tower);
		void display();
};

#endif