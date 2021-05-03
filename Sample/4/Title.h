
#ifndef SFMLSET_TITLE_H
#define SFMLSET_TITLE_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Title: public sf::Transformable, public sf::Drawable{
private:
    sf::Text title;
    sf::Font font;
    sf::Text Remaind;
 public:
    Title(){
        font.loadFromFile("OpenSans-Bold.ttf");
        title.setString("Input:");
        title.setFont(font);
        title.setCharacterSize(100);
        title.setStyle(sf::Text::Bold);
        title.setPosition(200.f, 50.f);
        Remaind.setFont(font);
        Remaind.setCharacterSize(100);
        Remaind.setStyle(sf::Text::Bold);
        Remaind.setPosition(200.f, 900.f);
        Remaind.setFillColor(sf::Color::Red);
    }
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void tooMuchletter(sf::String s){
        Remaind.setString(s);
    }
};

#endif