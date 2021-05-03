//
// Created by yi yao on 3/18/21.
//

#ifndef SFMLSET_TYPING_H
#define SFMLSET_TYPING_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
// #include "EventHandler.h"
// #include <map>
// #include "ObjectState.h"
#include "Stacks.h"
#include "Color.h"
#include "Word.h"
// #include "SnapShot.h"
#include "LinkedList.h"
#include "Iterator.h"
#include "Fonts.h"

class Typing : public sf::Transformable, public sf::Drawable {
public:
    Typing(){
        // font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(Fonts::getFont());
        text.setFillColor(sf::Color::Yellow);
        text.setCharacterSize(100);
        text.setStyle(sf::Text::Bold);
        position.x = 250.f;
        position.y = 240.f;
        text.setPosition(position);
        size = list.Size();
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();

    int width(){return position.x;};
    int height(){return position.y;};

    sf::Vector2f GetPosition (){return position;};

    void pop();
    void push(char s);
    void Enter(){position.y += 100.f; position.x = 250.f;}
    void Recursion(int n);

public:
    sf::Text text;
    // sf::String texting;
    sf::Font font;
    sf::Vector2f position;

    // SnapShot shot;
    // EventHandler data;
    LinkedList<sf::Text> list;
    int size;

    vector<sf::Text> string;
    Iterator<sf::Text> iter1;
    // String data;
};

#endif //SFMLSET_TYPING_H
