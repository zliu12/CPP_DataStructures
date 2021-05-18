#ifndef PROJECT1_ITEM_H
#define PROJECT1_ITEM_H

#include <SFML/Graphics.hpp>
//#include "Font.h"
#include <iostream>
#include <cmath>
#include "MouseEvent.h"

class Item: public sf::Transformable, public sf::Drawable{
private:
    sf::RectangleShape itembox;
    sf::Text itemName;

    const float x = 0;
    const float y = 0;
    const float HEIGHT = 25;
    const float WIDTH = 200;
//    const float x = 100;
//    const float y = 100;
    sf::Vector2f DefaultPos = {x, y};
//    const float HEIGHT = 25;
//    const float WIDTH = 200;
    sf::Vector2f size = {WIDTH, HEIGHT};
    sf::Font font;


    float itemX = 0;
    float itemY = 0;
    const float centerLine = WIDTH/2;
    const float horizontalLine = HEIGHT/2;

    MouseEvent<sf::RectangleShape> mouseEvent;

    void centerName();



public:
    Item();
    Item(std::string name);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void setBoxOutline(int size);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() const;
    void setDisplayName(std::string name);
    void setBoxFillColor(sf:: Color color);
    void setSize(sf::Vector2f size);
    sf::Rect<float> getLocalBounds();
    void setBoxOriginalColor();
    std::string getString() const;

    void getX(); //For Testing purpose only
};

#endif //PROJECT1_ITEM_H
