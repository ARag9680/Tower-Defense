#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Button.h"
#include "Map.h"
#include "NPC.h"
#include "Towers.h"
#include "Player.h"
#include "PlayerController.h"
#include "Player.h"
#include "Creep.h"
#include "Elite.h"
#include "Champion.h"


using namespace std;
using namespace sf;

class Main_Menu{
    private:
        string gameTitle;
        string instructionsTitle;
        string settingsTitle;
        bool isButtonSelected;
        bool gameStarted;
        vector<Button> buttons;
        Map* maps;
    public:
        Main_Menu();

        void handleClick(Vector2i mousePos, Event mouseButtonPressed, RenderWindow& window);
        void handleMouseHover(Vector2i mousePos);
        
        void initalizeButtons();
        void initalizeMap();

        void draw(RenderWindow& window);
        void drawMaps(RenderWindow& window, Player& player, Clock& clock, Vector2i mousePos, Event mouseButtonPressed);
        Map& getMaps();

        bool isGameStarted();

        ~Main_Menu();
};
#endif /* MAIN_MENU_H */
