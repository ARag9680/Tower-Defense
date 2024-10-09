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

        bool isGameStarted();
        
        void handleClick(Vector2i mousePos, Event mouseButtonPressed, RenderWindow& window);
        void handleMouseHover(Vector2i mousePos);

        void draw(RenderWindow& window);
        void drawMaps(RenderWindow& window);

        void initalizeButtons();
        void initalizeMap();

        ~Main_Menu();
};
#endif /* MAIN_MENU_H */
