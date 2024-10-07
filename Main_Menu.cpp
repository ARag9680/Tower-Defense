#include "Main_Menu.h"
Main_Menu::Main_Menu(){
    Button Start_Game("Start Game", 412,184);
    Start_Game.loadFont("Arial.ttf");
    buttons.push_back(Start_Game);
    cout << "Button 1 created" << endl;
    Button Instructions("Instructions", 412,284);
    buttons.push_back(Instructions);
    cout << "Button 2 created" << endl;
    Button Settings("Settings", 412,384);
    buttons.push_back(Settings);
    cout << "Button 3 created" << endl;
}

void Main_Menu::handleClick(Vector2i mousePos, Event mouseButtonPressed, RenderWindow& window){
    for (auto& button : buttons) {
        if (button.isMouseOver(mousePos)){
            if (button.isMouseClick(mouseButtonPressed) == true){
                if (button.getText() == "Start Game")
                {
                    cout << button.getText() << " was left clicked" << endl;
                    
                }
                if (button.getText() == "Instructions")
                {
                    cout << button.getText() << " was left clicked" << endl;
                }
                if (button.getText() == "Settings")
                {
                    cout << button.getText() << " was left clicked" << endl;
                }
            }
        }
    }
}

// void Main_Menu::viewInstructions(){

// }
// void Main_Menu::viewSettings(){

// }

void Main_Menu::draw(RenderWindow& window) {
    //cout << "Drawing Main Menu in Window" << endl;
    for (auto& button : buttons) {
        button.draw(window);
    }
}  
void Main_Menu::handleMouseHover(Vector2i mousePos) {
    for (auto& button : buttons) {
        if (button.isMouseOver(mousePos)) {
            button.setColor(Color::Cyan); // Change color on hover
        } else {
            button.setColor(Color::Blue); // Default color
        }
    }
}