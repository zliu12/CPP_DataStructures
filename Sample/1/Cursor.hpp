
#ifndef Cursor_hpp
#define Cursor_hpp

#include <SFML/Graphics.hpp>
#include "GUIComponent.hpp"
#include <iostream>
using namespace std;

class Cursor: public sf::Drawable, public sf::Transformable{
public:
    Cursor();
    Cursor(sf::Vector2f& size);
    
    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    void setPosition(float x, float y);
    
    void setSize(float x, float y);
    
private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    int blinkSpeed = 500;
    
    void toggleBlinkState();
    
    
};

#endif /* Cursor_hpp */
