
#include <SFML/Graphics.hpp>
#include "TextInput.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "typing");
    TextInput box;
    
    box.setLabel("Enter lines of code: ");
    //box.setLabelSize(25);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            box.addEventHandler(window, event);
        }
        box.update();
        window.clear();
        window.draw(box);
        window.display();
    }
}
