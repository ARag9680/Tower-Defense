#include "Main_Menu.h"


//-----------------Consructor and Destructors------------------// 
Main_Menu::Main_Menu(){
    initalizeButtons(); // As soon as the file is run created all buttons that are needed.
    cout << "Main Menu Objects Initalized" << endl;
}

Main_Menu::~Main_Menu(){
        // Destructor to clean up memory
    if (maps) {
        delete maps;  // Free the memory allocated to map
        maps = nullptr;
    }    
        buttons.clear();
}

//-----------------Buttons (Ownership and Creation)------------------// 

void Main_Menu::initalizeButtons(){ // Run in the default constructor.
    Button Start_Game("Start Game", 100,80);
    Start_Game.loadFont("Arial.ttf");
    buttons.push_back(Start_Game);
    cout << "Button 1 created" << endl;
    Button Instructions("Instructions", 100,160);
    buttons.push_back(Instructions);
    cout << "Button 2 created" << endl;
    Button Exit("Exit", 100,240);
    buttons.push_back(Exit);
    cout << "Button 3 created" << endl;
}

void Main_Menu::draw(RenderWindow& window) {
    //cout << "Drawing Main Menu in Window" << endl;
    for (auto& button : buttons) {
        button.draw(window); // Call the draw function of the Button class
    }
    if (showInstructionsImage) {
            window.draw(instructionsSprite);
    }
}  


//-----------------Map Functions (Ownership and Creation)------------------// 
void Main_Menu::initalizeMap(){
    cout << "Map pointer array, size: " << maps << endl;
    maps = new Map (Vector2i (20, 20));
    maps->readGridFromFile("grid_test.csv");
    cout<< "Map Initalized" <<endl;
    
}

Map& Main_Menu::getMaps() {
    return maps[0]; // Return a reference to the first map
}

void Main_Menu::drawMaps(RenderWindow& window, Player& player, Clock& clock, Vector2i mousePos, Event mouseButtonPressed){
    if (maps) {
        maps->display(window, player, clock, mousePos, mouseButtonPressed);  // Call the display method of the Map class
    } else {
        cerr << "Map not initialized!" << endl;
    }
}


//-----------------User Interaction------------------//
void Main_Menu::handleMouseHover(Vector2i mousePos) {
    for (auto& button : buttons) {
        if (button.isMouseOver(mousePos)) {
            button.setColor(Color::Cyan); // Change color on hover
        } else {
            button.setColor(Color::Blue); // Default color
        }
    }
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
                    if (!instructionsTexture.loadFromFile("instructions.jpg")) {
                        std::cerr << "Failed to load instructions image!" << std::endl;
                    }
                    instructionsSprite.setTexture(instructionsTexture);
                    instructionsSprite.setPosition(0, 50);  // Set position

                    // Set flag to display image
                    showInstructionsImage = true;           
                         
                }
                if (button.getText() == "Exit")
                {
                    cout << button.getText() << " was left clicked" << endl;
                    window.close();
                }
                else if (button.getText() == "Back"){
                    buttons.clear();
                    initalizeButtons();
                    showInstructionsImage = false;
                    gameStarted = false;
                }
            }
        }
    }
}

bool Main_Menu::isGameStarted(){
    return gameStarted;
}

