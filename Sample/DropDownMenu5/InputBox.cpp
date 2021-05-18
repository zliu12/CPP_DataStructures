#include "InputBox.h"

InputBox::InputBox() {
    this->setBoxOutline(2);

}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(mouseEvent.mouseClicked(*this,window)){
//        this->setBoxFillColor(sf::Color::Cyan);
        clicked = true;
   }
    else if(mouseEvent.mouseClicked(window,event)){
        clicked = false;
    }
//    Item::addEventHandler(window, event);
}

void InputBox::update() {
    this->setDisplayName(getString());
}

Snapshot &InputBox::getSnapshot() {

}

void InputBox::applySnapshot(const Snapshot &snapshot) {

}

sf::Vector2f InputBox::getPosition() {
    return this->getPosition();
}

sf::Rect<float> InputBox::getLocalBounds() {
    return this->getLocalBounds();
}

void InputBox::setPosition(sf::Vector2f position) {
    this->setPosition(position);
}

void InputBox::setSize(sf::Vector2f size) {
    this->setSize(size);
}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Item::draw(window, states);
}

bool InputBox::isClicked() const {
    return clicked;
}

