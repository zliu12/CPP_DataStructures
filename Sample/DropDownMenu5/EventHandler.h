#ifndef PROJECT1_EVENTHANDLER_H
#define PROJECT1_EVENTHANDLER_H
#include "SFML/Graphics.hpp"
class EventHandler {
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //PROJECT1_EVENTHANDLER_H
