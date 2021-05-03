
#include "Item.h"

Item::Item(/* args */){
    // font.loadFromFile("OpenSans-Bold.ttf");
    size = sf::Vector2f(400,100);
    box.setSize(size);
    box.setFillColor(sf::Color::Transparent);

    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setFont(Fonts::getFont());
    text.setCharacterSize(50);
    // text.setString("data");
}

void Item::String(sf::String s){
    text.setString(s);
    string data = s;
    cout << data << endl;
}

void Item::Position(float x, float y){
    box.setPosition(x,y);
    // cout << x << "   " << y << endl;
    // float X = box.getLocalBounds().height;
    // float Y = box.getLocalBounds().width;
    // cout << X << "   " <<  Y << endl;
    text.setPosition(x,y);
}

void Item::setColor(sf::Color color){
    box.setFillColor(color);
}

sf::String Item::getString(){
    return text.getString();
}

sf::FloatRect Item::getLocalBounds(){
    return box.getGlobalBounds();
}

float Item::getPositiony(){
    return box.getPosition().y;
}