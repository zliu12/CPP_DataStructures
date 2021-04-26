
#ifndef EventHandler_hpp
#define EventHandler_hpp
#include <SFML/Graphics.hpp>

// interface
class EventHandler{
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    
    virtual void update() = 0;
    
};

#endif /* EventHandler_hpp */
