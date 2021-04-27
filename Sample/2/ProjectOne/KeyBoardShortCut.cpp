#include "KeyBoardShortCut.h"
bool KeyBoardShortCut::isUndo()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard
                                                                                        ::RControl))
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            return true;
    return false;
}
