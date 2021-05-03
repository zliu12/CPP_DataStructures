#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "MyClass.h"
// #include "Typing.h"
#include "Input.h"
#include "Itemlist.h"
#include "InputBox.h"
#include "DropDown.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(3000,2000),"SFML Project");
//Text project
    // sf::Text text;
    // sf::Text shadow;
    // text.setString("CS 008 HOME");
    // shadow.setString("CS 008 HOME");
    //     //font
    // sf::Font font;
    // font.loadFromFile("OpenSans-Bold.ttf");
    // text.setFont(font);
    // shadow.setFont(font);
    // //color
    // sf::Color white = sf::Color::White;
    // sf::Color color = sf::Color::White;
    // text.setFillColor(color);
    // white.a = 50;
    // shadow.setFillColor(white);
    // shadow.setStyle(sf::Text::Bold);
    // shadow.setPosition(300.f, 500.f);
    // shadow.setScale(sf::Vector2f(6.38f, -5.f));

    // text.setCharacterSize(200);
    // text.setStyle(sf::Text::Bold);
    // text.setPosition(300.f, 150.f);
//Bouncing ball
    //MyClass ball(10,5);
    // Typing typing;
    // sf::Texture texture;

    // texture.create(500,500);
    // texture.loadFromFile("White.png"); 
    // texture.update(window);
    // sf::Sprite sprite;
    // sprite.setTexture(texture);
    // sprite.setPosition(300.f, 250.f);
    // sprite.setColor(sf::Color::White);
    // sprite.setTextureRect(sf::IntRect(1000, 1000, 1000, 500));

    // sf::Cursor cursor;
    // cursor.loadFromSystem(sf::Cursor::Hand);
    // sf::RectangleShape cursor(sf::Vector2f(100.f, 100.f));
    // cursor.setFillColor(sf::Color::Red);
    // cursor.setPosition(300.f, 250.f);

    // sf::Text title;
    // sf::Font font;
    // font.loadFromFile("OpenSans-Bold.ttf");
    // title.setString("Input:");
    // title.setFont(font);
    // title.setCharacterSize(100);
    // title.setStyle(sf::Text::Bold);
    // title.setPosition(200.f, 50.f);

    // Input data;
    vector<string> vector {"abcdef", "Apples", "Bananas", "Hello", "Hello Nurse!"};
    DropDown down(vector);
    down.setPosition(0, 0);
    // Itemlist list(vector);
    // InputBox box;
    // Item i;
    
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            // data.addEventHandler(window, event);
            down.addEventHandler(window, event);
            // list.addEventHandler(window, event);
            // History::pushHistory(t);
        }
    //This function makes the ball move in the window
        //ball.bounce(window);

        // data.update();
        down.update();
        // cout << "Update" << endl;
        window.clear(sf::Color::Black);
        // window.draw(title);
        // window.draw(sprite);
        // window.setMouseCursor(cursor);
        // window.draw(data);
        //window.draw(ball);
        //window.draw(shadow);
        // window.draw(list);
        // window.draw(box);
        window.draw(down);
        // cout << "Draw" << endl;
        window.display();
    }
    cout << "End   End" << endl;
    return 0;
}