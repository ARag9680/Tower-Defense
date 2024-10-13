#include "Main_Menu.h"

Main_Menu::Main_Menu(){
    initalizeButtons(); // As soon as the file is run created all buttons that are needed.
    cout << "Main Menu Objects Initalized" << endl;
}
bool Main_Menu::isGameStarted(){
    return gameStarted;
}
void Main_Menu::initalizeButtons(){ // Run in the default constructor.
    Button Start_Game("Start Game", 100,80);
    Start_Game.loadFont("Arial.ttf");
    buttons.push_back(Start_Game);
    cout << "Button 1 created" << endl;
    Button Instructions("Instructions", 100,160);
    buttons.push_back(Instructions);
    cout << "Button 2 created" << endl;
    Button Settings("Settings", 100,240);
    buttons.push_back(Settings);
    cout << "Button 3 created" << endl;
}

void Main_Menu::initalizeMap(){
    cout << "Map pointer array, size: " << maps << endl;
    maps = new Map (20, 20);
    cout<< "Map Initalized" <<endl;
    Creep example_creep(Vector2f(0,0));
    Elite example_elite(Vector2f(0, 30));
    Champion example_champion(Vector2f(50, 0), 2);
    cout << "Enemies Initalized"<< endl;
    maps[0].spawnNPC(example_creep);
    maps[0].spawnNPC(example_elite);
    maps[0].spawnNPC(example_champion);
}

Map& Main_Menu::getMaps() {
    return maps[0]; // Return a reference to the first map
}

void Main_Menu::handleClick(Vector2i mousePos, Event mouseButtonPressed, RenderWindow& window){
    for (auto& button : buttons) {
        if (button.isMouseOver(mousePos)){ //check that the mouse is over a button,
            if (button.isMouseClick(mouseButtonPressed)){ //check if the button was clicked,
                if (button.getText() == "Start Game") //Then check the name of the button and perform the following functions.
                {
                    cout << button.getText() << " was left clicked" << endl;
                    buttons.clear();
                    initalizeMap();
                    window.clear();
                    gameStarted = true;
                }
                if (button.getText() == "Instructions")
                {
                    cout << button.getText() << " was left clicked" << endl;
                    buttons.clear();
                    Button Back("Back", 0, 0);
                    buttons.push_back(Back);
                }
                if (button.getText() == "Settings")
                {
                    cout << button.getText() << " was left clicked" << endl;
                    buttons.clear();
                    Button Back("Back", 0, 0);
                    buttons.push_back(Back);
                }
                if (button.getText() == "Back"){
                    buttons.clear();
                    initalizeButtons();
                    gameStarted = false;
                }
            }
        }
    }
}

void Main_Menu::draw(RenderWindow& window) {
    cout << "Drawing Main Menu in Window" << endl;
    for (auto& button : buttons) {
        button.draw(window); // Call the draw function of the Button class
    }
}  
void Main_Menu::drawMaps(RenderWindow& window){
    if (maps) {
        maps->display(window);  // Call the display method of the Map class
    } else {
        cerr << "Map not initialized!" << endl;
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

Main_Menu::~Main_Menu(){
        // Destructor to clean up memory
    if (maps) {
        delete maps;  // Free the memory allocated to map
        maps = nullptr;
    }    
        buttons.clear();
}