#include "Main_Menu.h"

int main(){
    // Create a window object
    RenderWindow window(VideoMode(1024, 768), "SFML Window"); //We can change this to whatever suits.
    cout << "SFML Window Drawn" << endl;
    //Create Main Menu;
    Main_Menu Main_Window;
    
    // Main game loop (runs as long as the window is open)
    while (window.isOpen())
    {
        // Event processing
        Vector2i mousePos = Mouse::getPosition(window);
        Event event;
        
        Main_Window.handleMouseHover(mousePos); //Shows user that the button is actively being hovered over.
        Main_Window.handleClick(mousePos, event, window); //Handles all clicks on buttons.
        
        while (window.pollEvent(event))
        {
            // Close the window if the close button is pressed
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White); //Setting window to white before drawing on top of

        //Draw objects onto the screen
        if (Main_Window.isGameStarted()) {  // This is a bool tracking whether the game has started before drawing
            cout<< "Drawing Maps" <<endl;
            Main_Window.drawMaps(window);  //  Draw the map after Start game has been pressed.
        } else {
            Main_Window.draw(window);  // Draw the main menu (buttons) if game is not started.
        }
        // Display what was drawn
        
        window.display();
    }

    return 0;
}