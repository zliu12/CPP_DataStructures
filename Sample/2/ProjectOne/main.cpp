#include <iostream>
#include"Typer.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
    Typer t;

    while(window.isOpen())
    {
//        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
//        sf::FloatRect PairSize = t.getBoxSize1();

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            t.addEventHandler(window, event);

        }
        t.update();
        window.clear(sf::Color::Black);
        window.draw(t);
        window.display();
    }
}
