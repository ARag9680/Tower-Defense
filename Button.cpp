#include "Button.h"
Font Button::font;

bool Button::loadFont(const string& fontPath) {
    if (!font.loadFromFile(fontPath)) {
        cerr << "Error: Could not load font '" << fontPath << "'" << endl;
        return false;  // Return false if loading fails
    }
    cout << "Font loaded." << endl;
    return true;  // Return true if loading succeeds
}

Button::Button(const string& text, float x, float y) {
    buttonShape.setSize(Vector2f(200, 50));
    buttonShape.setPosition(x, y);
    buttonShape.setFillColor(Color::Red);
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(Color::Black);
    buttonText.setPosition(x + 10, y + 10);
}
void Button::draw(RenderWindow& window) {
    //cout << "Drawing button at: " << buttonShape.getPosition().x << ", " << buttonShape.getPosition().y << endl;
    window.draw(buttonShape);
    if (buttonText.getFont() != nullptr) {
        //cout << "Font is valid" << endl;
        window.draw(buttonText);
    } else {
        cerr << "Font is not set!" << endl;
    }
}
bool Button::isMouseOver(Vector2i mousePos) {
    return buttonShape.getGlobalBounds().contains(static_cast<Vector2f>(mousePos));
}
bool Button::isMouseClick(Event mouseButtonPressed){
    return (mouseButtonPressed.type == Event::MouseButtonPressed && mouseButtonPressed.mouseButton.button == Mouse::Left);
}
void Button::setColor(const Color& color) {
    buttonShape.setFillColor(color);
}
string Button::getText(){
    return buttonText.getString();
}