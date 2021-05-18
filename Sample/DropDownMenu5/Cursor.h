//
// Created by xu200 on 4/11/2021.
//

#ifndef PROJECT1_CURSOR_H
#define PROJECT1_CURSOR_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "GUIComponent.h"
#include "States.h"
#include "MouseEvent.h"
#include "Textbox.h"


class Cursor : public States, public sf::Drawable{

public:
    Cursor();
    void blinking();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) ;
    virtual void update() ;
    virtual Snapshot& getSnapshot() ;
    virtual void applySnapshot(const Snapshot& snapshot);
    void set_Position();
    void set_Position(sf::Vector2f position);



private:
    //States state = BLINKON;
    sf::Text cursor;
    sf::Clock clock;
    States state;
    sf::Font font;
    MouseEvent<Textbox> mouseEvent;
    Textbox textbox;
//    Typing text;

    //sf::String cursorID;

};

#endif //PROJECT1_CURSOR_H
