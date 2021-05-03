
#ifndef SFMLSET_INPUT_H
#define SFMLSET_INPUT_H
#include <SFML/Graphics.hpp>
#include <iostream>
// #include "Stacks.h"
// #include "EventHandler.h"
// #include "Cursor.h"
// #include "Stacks.h"
#include "Typing.h"
#include "Title.h"
#include "Cursor.h"
#include "Box.h"
// #include "SnapShot.h"

class Input: public sf::Transformable, public sf::Drawable{
    private:
    // sf::Text title;
    Title title;
    Cursor cursor;
    Typing typing;
    Box box;

    sf::Font font;
    sf::Vector2f position;
    char texting;

    sf::Text text;

    public:
        Input(){
            font.loadFromFile("OpenSans-Bold.ttf");
            text.setFont(font);
            text.setFillColor(sf::Color::Black);
            text.setCharacterSize(100);
            text.setStyle(sf::Text::Bold);
            text.setPosition(300.f, 250.f);
        }
        void update();
        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
        void addEventHandler(sf::RenderWindow& window, sf::Event event);
};

#endif