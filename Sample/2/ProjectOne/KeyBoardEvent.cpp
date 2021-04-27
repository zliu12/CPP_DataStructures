#include "KeyBoardEvent.h"
KeyBoardEvent::KeyBoardEvent(){}
sf::Color KeyBoardEvent::KeyBoardColor(sf::RenderWindow& window, sf::Event event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
        return sf::Color::Red;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Comma) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Divide) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Equal) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Period) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Quote) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen))
        return sf::Color::Green;
    else
        return sf::Color::White;
}