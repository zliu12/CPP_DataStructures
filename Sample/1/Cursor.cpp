#include "Cursor.hpp"


Cursor::Cursor(){
    sf::Vector2f vec(5, 50);
    cursor.setFillColor(sf::Color::White);
    cursor.setOutlineThickness(3);
    cursor.setSize(vec);
    clock.restart();
}

Cursor::Cursor(sf::Vector2f& size){
    cursor.setFillColor(sf::Color::White);
    cursor.setOutlineThickness(3);
    cursor.setSize(size);
    clock.restart();
}



void Cursor::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(cursor);
}


void Cursor::addEventHandler(sf::RenderWindow& window, sf::Event event){
    // nothing
}


void Cursor::update(){
    if(clock.getElapsedTime() >= sf::milliseconds(500)){
        clock.restart();
        
        if(States::isStateEnabled(States::BLINKON)){
            cursor.setFillColor(sf::Color::White);
        }else{
            cursor.setFillColor(sf::Color::Transparent);
            cursor.setOutlineColor(sf::Color::Transparent);
        }
        
        toggleBlinkState();
    }
}


void Cursor::toggleBlinkState(){
    
    if(States::isStateEnabled(States::BLINKON))
        States::setStateEnable(States::BLINKON, false);
    else
        States::setStateEnable(States::BLINKON, true);
}


void Cursor::setPosition(float x, float y){
    cursor.setPosition(x, y);
}

void Cursor::setSize(float x, float y){
    cursor.setSize(sf::Vector2f(x,y));
}

