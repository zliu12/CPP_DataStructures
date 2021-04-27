#ifndef PROJECTONETEXTBOX_EVENTHANDLER_H
#define PROJECTONETEXTBOX_EVENTHANDLER_H
#include<SFML/Graphics.hpp>

class EventHandler {
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //PROJECTONETEXTBOX_EVENTHANDLER_H
