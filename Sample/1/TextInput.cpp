
#include "TextInput.hpp"

TextInput::TextInput(){
    textBox.setPosition(50, 400);
    typing.setPosition(60, 400);
    label.add("Enter a line of code: ");
    label.setCharacterSize(60);
    label.setPosition(50, 300);
    if(!font.loadFromFile("OpenSans-Bold.ttf")){
        cout << "font is not loading\n";
    }
    label.setFont(font);
}

void TextInput::setLabel(string word){
    label.setString(word);
}

void TextInput::setLabelSize(int size){
    label.setCharacterSize(size);
    label.setPosition(textBox.getPosition().x, textBox.getPosition().y - textBox.getOutlineThickness() - size - 10);
}


void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(textBox);
    window.draw(typing);
    window.draw(label);
}

// from EventHandler
void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(MouseEvents<TextInputBox>::mouseClicked(textBox, window)){
        States::setStateEnable(States::HIDDEN, false);
    }else if(MouseEvents<TextInputBox>::mouseClicked(window, event) && !MouseEvents<TextInputBox>::hovered(textBox, window)){
        States::setStateEnable(States::HIDDEN, true);
    }
    
    typing.addEventHandler(window, event);
}

void TextInput::update(){
    typing.update();
}

////from SnapshotInterface
//Snapshot& TextInput::getSnapshot(){
//
//};
//
//
//void TextInput::applySnapshot(const Snapshot& snapshot){
//
//}
