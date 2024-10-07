#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Button.h"
using namespace std;
using namespace sf;

class Main_Menu{
    private:
        string gameTitle;
        string instructionsTitle;
        string settingsTitle;
        bool isButtonSelected;
        vector<Button> buttons;
    public:
        Main_Menu();
        void handleClick(Vector2i mousePos, Event mouseButtonPressed, RenderWindow& window);
        // void viewInstructions();
        // void viewSettings();
        void draw(RenderWindow& window);
        void handleMouseHover(Vector2i mousePos);
        void initalizeButtons();
        ~Main_Menu();
};
#endif /* MAIN_MENU_H */
