#ifndef PROJECT1_TYPING_H
#define PROJECT1_TYPING_H
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MultiText.h"
#include "Cursor.h"
const float typeInputX = 105;
const float typeInputY = 208;
class Typing : public sf::Text{
private:
    sf::Text object;
    sf::Font font;
    std::string Userinput = "";
    MultiText MulText;
    Cursor cursor;
    int n = 15;
    const int WIDTH = 300;
    const float HEIGHT = 30;
    const int x = 102;
    const int y = 204;


public:
    Typing();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    sf::Vector2f get_Position();
};

#endif //PROJECT1_TYPING_H
