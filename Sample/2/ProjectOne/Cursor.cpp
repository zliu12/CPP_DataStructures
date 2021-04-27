#include "Cursor.h"
Cursor::Cursor()
{
    cursor.setSize({5,25});
    cursor.setPosition({41,101});

}
void Cursor::setSize(sf::Vector2f size)
{
    cursor.setSize(size);
}
void Cursor::setPosition(sf::Vector2f size)
{
    cursor.setSize(size);
}
void Cursor::updatePosition(sf::Vector2f v)
{
    cursor.setPosition(v.x+13, v.y);
}

void Cursor::update(State s)
{
    if(s == HIDDEN)
    {
        cursor.setFillColor(sf::Color::Black);
    }
    else
    {
        cursor.setFillColor(sf::Color::White);
    }
    if(clock.getElapsedTime().asMilliseconds() > blinkSpeed)
    {
        toggleBlinkState();
        clock.restart();
    }
}
sf::Vector2f Cursor::getCursorPosition()
{
    return cursor.getPosition();
}

void Cursor::toggleBlinkState()
{
    if(ss == BITNKON)
    {
        cursor.setFillColor(sf::Color::White);
        cursor.setSize({5,25});
        ss = BINKOFF;
    }
    else
    {
        cursor.setSize({0,0});
        ss = BITNKON;
    }
}
void Cursor::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

//    if(isStateEnable(BITNKON))
//    {
//        std::cout << "Not hidden" << std::endl;
//        cursor.setScale(1,1);
//
//    }
//    else
//    {
//        std::cout << " hidden" << std::endl;
//        cursor.setScale(0,0);
//    }


}

void Cursor::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(cursor);
}
sf::FloatRect Cursor::getGlobalBounds()
{
    return cursor.getGlobalBounds();
}