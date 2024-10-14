#include "Main_Menu.h"

int main(){
    // Create a window object
    RenderWindow window(VideoMode(400,400), "Tower Defense");
    window.setPosition(Vector2i(100,100));
    
    cout << "SFML Window Drawn" << endl;
    //Create Main Menu;
    Main_Menu Main_Window;
    Player player(100, "Player1", 100);

    Main_Window.initalizeMap(); // Initialize map

    player.setPlayerPosition(Vector2f(400,400));
    PlayerController player_cont("Player_cont");
    
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
            // cout<< "Drawing Maps" <<endl;
            Main_Window.drawMaps(window);  //  Draw the map after Start game has been pressed.
            for (std::vector<NPC>::iterator npc_it = Main_Window.getMaps().getNPCs().begin(); npc_it != Main_Window.getMaps().getNPCs().end(); ++npc_it) {
                npc_it->move(Main_Window.getMaps() , player.getPlayerPosition());
            }
        } else {
            Main_Window.draw(window);  // Draw the main menu (buttons) if game is not started.
        }
        // Display what was drawn

        player_cont.initializeInput(player); // Check for click

        
        window.display();
    }

    return 0;
}