#include "Button.h"
#include "Main_Menu.h"
int main(){
    // Create a window object
    RenderWindow window(VideoMode(1024, 768), "SFML Window");
    cout << "Window Drawn" << endl;
    //Create Main Menu;
    Main_Menu Main_Window;
    
    // Main game loop (runs as long as the window is open)
    while (window.isOpen())
    {
        // Event processing
        Vector2i mousePos = Mouse::getPosition(window);
        Event event;
        
        Main_Window.handleMouseHover(mousePos);
        Main_Window.handleClick(mousePos, event, window);
        
        while (window.pollEvent(event))
        {
            // Close the window if the close button is pressed
            if (event.type == Event::Closed)
                window.close();
        }
        //cout << "Window Color White" << endl;
        // Clear the window with a black color
        window.clear(Color::White);

        //Draw objects onto the screen
        Main_Window.draw(window);
    
        // Display what was drawn
        
        window.display();
    }

    return 0;
}