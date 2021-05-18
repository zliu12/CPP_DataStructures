#include "Textbox.h"
Textbox::Textbox(){
    textbox.setSize({WIDTH,HEIGHT});
    textbox.setOutlineColor(sf::Color::White);
    textbox.setFillColor(sf::Color::Black);
    textbox.setOutlineThickness(3);
    textbox.setPosition({x,y});
}
void Textbox::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(textbox);
}
void Textbox::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        textbox.setSize({WIDTH, HEIGHT + n});
        n += 15;
    }
//    if (event.type == sf::Event::TextEntered) {
//            if (textbox.getSize().y != HEIGHT) {
//                if (event.text.unicode == '\b') {
//                textbox.setSize({WIDTH, HEIGHT - 30});
//
//            }
//        }
//    }
}
void Textbox::update(){

}
Snapshot& Textbox::getSnapshot(){

}
void Textbox::applySnapshot(const Snapshot& snapshot){

}

sf::Vector2f Textbox::getPosition(){
    return textbox.getPosition();
}

sf::Rect<float> Textbox::getLocalBounds(){
    return textbox.getLocalBounds();
}