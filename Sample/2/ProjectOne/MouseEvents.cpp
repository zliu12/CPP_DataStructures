#ifndef PROJECTONETEXTBOX_MOUSEEVENTS_CPP
#define PROJECTONETEXTBOX_MOUSEEVENTS_CPP
#include "MouseEvents.h"
//template <class T>
//static bool MouseEvents<T>::mouseClicked(sf::RectangleShape window, sf::Event event)
//{
//
//}
//template <class T>
//static bool MouseEvents<T>::mouseClicked(T& object, sf::RenderWindow& window)
//{
//    sf::FloatRect boxSize = object.getBoxGlobal();
//    if(mouseClicked(boxSize))
//        return true;
//    else
//        return false;
//
//}
template <class T>
MouseEvents<T>::MouseEvents(){}
template <class T>
bool MouseEvents<T>::mouseClicked(sf::RectangleShape object, sf::RenderWindow& window)
{
//sf::FloatRect boxSize = object.getGlobalBounds();
//    if(mouseDSingleClicked())
//    return true;
//    else
//    return false;
}
template <class T>
bool MouseEvents<T>::mouseDSingleClicked(sf::RectangleShape window, sf::Event event)
{
//    sf::Vector2f temp =  (sf::Vector2f)window.getSize();
//    sf::Vector2<int> pos = sf::Mouse::getPosition();
//    if (event.type == sf::Event::MouseButtonPressed) {
//        if (event.mouseButton.button == sf::Mouse::Left && temp) {
//            return true;
//        }
//    }
//    return false;
}

#endif