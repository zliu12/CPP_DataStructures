#include "Item.h"

Item::Item() {
    itembox.setSize(size);
    itembox.setPosition(DefaultPos);
    itembox.setFillColor(sf::Color::Black);
    itembox.setOutlineColor(sf::Color::White);
    itembox.setOutlineThickness(0);
}

Item::Item(std::string name){
//    itembox.setSize(size);
//    itembox.setPosition(DefaultPos);
//    itembox.setFillColor(sf::Color::Black);
//    itembox.setOutlineColor(sf::Color::White);
//    itembox.setOutlineThickness(1);

    itemName.setString(name);
    if (!font.loadFromFile("OpenSans-Bold.ttf")){
        std::cout<< "Font couldn't load the file"<<std::endl;
    }
    itemName.setCharacterSize(18);
    itemName.setFont(font);
    centerName();

}

void Item::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(itembox);
    window.draw(itemName);
}

void Item::centerName() {
    float itemCenter = itemName.getLocalBounds().width /2;
    float itemHalfHeight = itemName.getGlobalBounds().height /2;
    itemX = itembox.getPosition().x + abs(centerLine - itemCenter);
    itemY = itembox.getPosition().y + abs(horizontalLine - itemHalfHeight) - 2  ;

    sf::Vector2f posItem = {itemX, itemY};
    itemName.setPosition(posItem);

//    std::cout<<"center: "<<itemCenter<<std::endl;
}

void Item::getX(){

}

void Item::setBoxOutline(int size) {
    itembox.setOutlineThickness(size);
}

void Item::setPosition(sf::Vector2f position){
    itembox.setPosition(position);
    centerName();
}

sf::Vector2f Item::getPosition() const {
    return itembox.getPosition();
}

void Item::setDisplayName(std::string name) {
    itemName.setString(name);
    if (!font.loadFromFile("OpenSans-Bold.ttf")){
        std::cout<< "Font couldn't load the file"<<std::endl;
    }
    itemName.setCharacterSize(18);
    itemName.setFont(font);
    centerName();
}

void Item::setBoxFillColor(sf::Color color) {
    itembox.setFillColor(color);
}

void Item::setSize(sf::Vector2f size) {
    itembox.setSize(size);
}

sf::Rect<float> Item::getLocalBounds(){
    return itembox.getLocalBounds();
}

void Item::setBoxOriginalColor() {
    itembox.setFillColor(sf::Color::Black);
}


void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
        if (mouseEvent.hovered(itembox, window)) {
           setBoxFillColor(sf::Color::Blue);
        } else {
           setBoxOriginalColor();
        }

}

std::string Item::getString() const {
    return itemName.getString();
}
