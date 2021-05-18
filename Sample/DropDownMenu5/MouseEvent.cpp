#ifndef PROJECT1_MOUSEEVENT_CPP
#define PROJECT1_MOUSEEVENT_CPP
#include "MouseEvent.h"
template <class T>
bool MouseEvent<T>::mouseClicked(T& object, sf::RenderWindow& window){
    sf::Vector2i position = sf::Mouse::getPosition(window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(position.x >= object.getPosition().x
        && position.y <= object.getLocalBounds().height + object.getPosition().y
        && position.x <= object.getPosition().x+object.getLocalBounds().width
        && position.y >= object.getPosition().y){
            //std:: cout << "The object has been clicked."<<std::endl;
            return true;
        }

    }
    return false;
}

template <class T>
bool MouseEvent<T>::mouseClicked( sf::RenderWindow& window, sf::Event event){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        //std:: cout << "The window has been clicked."<<std::endl;
        return true;
    }
    return false;
}

template <class T>
bool MouseEvent<T>::mouseDoubleClicked(){

}

template <class T>
bool MouseEvent<T>::mouseTripleClicked(){

}


template <class T>
bool MouseEvent<T>::draggedOver(T& object, sf::RenderWindow& window, sf::Event event){

}

template <class T>
bool MouseEvent<T>::hovered(T& object, sf::RenderWindow& window){
    sf::Vector2i position = sf::Mouse::getPosition(window);
    if(position.x >= object.getPosition().x
       && position.y <= object.getLocalBounds().height + object.getPosition().y
       && position.x <= object.getPosition().x+object.getLocalBounds().width
       && position.y >= object.getPosition().y){
        //std:: cout << "The object has been hovered."<<std::endl;
        return true;
    }
    return false;
}

#endif