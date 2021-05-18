#include "KeyboardShortcut.h"
bool KeyboardShortcut::isUndo(sf::Event e){

    if (e.type == sf::Event::KeyPressed){
        if(e.key.control){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
                std::cout<< "The undo is pressed."<<std::endl;
                return true;
            }
        }

    }
    return false;

}