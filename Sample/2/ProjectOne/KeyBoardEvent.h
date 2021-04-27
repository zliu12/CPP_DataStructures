#ifndef PROJECTONETEXTBOX_KEYBOARDEVENT_H
#define PROJECTONETEXTBOX_KEYBOARDEVENT_H

#include <SFML/Graphics.hpp>
class KeyBoardEvent {
private:
public:
    KeyBoardEvent();
    sf::Color KeyBoardColor(sf::RenderWindow& window, sf::Event event);
};


#endif //PROJECTONETEXTBOX_KEYBOARDEVENT_H
