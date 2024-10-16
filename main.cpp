#include "Main_Menu.h"

int main(){
    // Create a window object
    RenderWindow window(VideoMode(400,500), "Tower Defense");
    // Sets window to middle of the screen
    window.setPosition(Vector2i((sf::VideoMode::getDesktopMode().width - window.getSize().x)/2, 
        (sf::VideoMode::getDesktopMode().height - window.getSize().y)/2));
    
    cout << "SFML Window Drawn" << endl;
    //Create Main Menu;
    Main_Menu Main_Window;
    Player player(100, "Player1", 100);

    player.setPlayerPosition(Vector2f(350, 350));    

    Main_Window.initalizeMap();
    
    // Main game loop (runs as long as the window is open)
    while (window.isOpen())
    {
        // Event processing
        Vector2i mousePos = Mouse::getPosition(window);
        Event event;
        Clock clock;
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
                   
            Main_Window.drawMaps(window, player, clock, mousePos, event);//  Draw the map after Start game has been pressed.
            player.drawPlayerIndicator(&window);  
            for (std::vector<NPC>::iterator npc_it = Main_Window.getMaps().getNPCs().begin(); npc_it != Main_Window.getMaps().getNPCs().end(); ++npc_it) {
                npc_it->move(Main_Window.getMaps() , player.getPlayerPosition());
            }
            
        } else {
            Main_Window.draw(window);  // Draw the main menu (buttons) if game is not started.
        }

        // Display what was drawn
        window.display();
    }

    return 0;
}