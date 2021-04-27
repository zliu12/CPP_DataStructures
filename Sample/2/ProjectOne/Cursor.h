#ifndef PROJECTONETEXTBOX_CURSOR_H
#define PROJECTONETEXTBOX_CURSOR_H
//#include "EventHandler.h"
#include "States.h"
#include <SFML/Graphics.hpp>
class Cursor : public sf::Drawable{
private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    State ss;
    int blinkSpeed = 500;
    void toggleBlinkState();

public:
    Cursor();
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f size);
    void updatePosition(sf::Vector2f v);
    sf::Vector2f getCursorPosition();
     void addEventHandler(sf::RenderWindow& window, sf::Event event);
   void update(State s);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    sf::FloatRect getGlobalBounds();
};


#endif //PROJECTONETEXTBOX_CURSOR_H
