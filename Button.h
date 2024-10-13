#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace sf;
class Button {
    private:
        RectangleShape buttonShape;
        Text buttonText;
        static Font font;
    public:
        Button(){}
        Button(const string& text, float x, float y);
        bool isMouseOver(Vector2i mousePos);
        bool isMouseClick(Event mouseButtonPressed);
        void draw(RenderWindow& window);
        void setColor(const Color& color);
        static bool loadFont(const string& fontPath); 
        string getText();
        ~Button();
};
#endif /* BUTTON_H */
