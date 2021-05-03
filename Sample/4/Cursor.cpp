#ifndef SFMLSET_CURSOR_CPP
#define SFMLSET_CURSOR_CPP

#include "Cursor.h"

Cursor::Cursor(){
    cursor.setSize(sf::Vector2f(10.f, 100.f));
    cursor.setFillColor(sf::Color::Black);
    cursor.setPosition(300.f, 280.f);
    x = 300;
    time = clock.getElapsedTime();
}


void Cursor::setSize(sf::Vector2f size){
    cursor.setSize(size);
}


void Cursor::update(sf::Vector2f position){
    cursor.setPosition(position);
    if(clock.getElapsedTime().asMilliseconds() > blink){
        cursor.setFillColor(sf::Color::White);
    }

    if(clock.getElapsedTime().asMilliseconds() > (blink * 2)){
        // cout << clock.getElapsedTime().asMilliseconds() << " " << endl;
        clock.restart();
        cursor.setFillColor(sf::Color::Black);
    }
}


void Cursor::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(cursor,states);
}

#endif