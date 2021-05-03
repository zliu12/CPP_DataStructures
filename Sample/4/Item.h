
#ifndef SFMLSET_ITEM_H
#define SFMLSET_ITEM_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Fonts.h"
using namespace std;

class Item: public sf::Transformable, public sf::Drawable{
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Vector2f size;
    // sf::Font font;
public:
    Item(/* args */);
    void String(sf::String s);
    void Position(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const{
        window.draw(box,states);   
        window.draw(text,states);
    }
    void setColor(sf::Color color);
    sf::String getString();
    sf::FloatRect getLocalBounds();
    float getPositiony();
};

#endif