//
// Created by Rena on 4/10/21.
//

#include "Box.h"
Box::Box()
{
    rect.setSize({500,30});
    rect.setFillColor(sf::Color::Black);
    rect.setPosition({50,100});
    rect.setOutlineThickness(5);
    rect.setOutlineColor(sf::Color::White);
}
sf::RectangleShape Box::getRect()
{
    return rect;
}

sf::FloatRect Box::getBoxGlobal()
{
    return rect.getGlobalBounds();
}

void Box::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(rect);
}
sf::Vector2f Box::getBoxPosition()
{
    return rect.getPosition();
}

sf::Vector2f Box::getBoxSize()
{
    return rect.getSize();
}
