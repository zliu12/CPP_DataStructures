
#include "TextInputBox.hpp"


TextInputBox::TextInputBox()
: TextInputBox(900, 100, sf::Color::White){
    
}

TextInputBox::TextInputBox(const sf::Vector2f& size)
: TextInputBox(size.x, size.y, sf::Color::White){
    
}


TextInputBox::TextInputBox(float width, float height, sf::Color color)
: sf::RectangleShape({width, height}){
    setOutlineThickness(10);
    setOutlineColor(sf::Color::White);
    setFillColor(sf::Color::Transparent);
    
}


TextInputBox::TextInputBox(sf::Color color)
: TextInputBox(900, 100, color){
    
}


