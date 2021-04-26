
#include "KeyShortcuts.hpp"

bool KeyShortcuts::isUndo(){
    if(
           ( sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem) )&&
           ( sf::Keyboard::isKeyPressed(sf::Keyboard::Z) )
       ){
        return true;
    }else{
        return false;
    }
}
