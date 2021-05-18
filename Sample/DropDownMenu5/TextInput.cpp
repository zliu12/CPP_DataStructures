
#include "TextInput.h"
TextInput::TextInput() {
//    if (!font.loadFromFile("OpenSans-Bold.ttf")){
//        std::cout<<"Can not open the font file"<<std::endl;
//    }
//    input.setFont(font);
//    input.setCharacterSize(18);
//    input.setPosition(105,208);
//    input.setFillColor(sf::Color::White);
}

void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(input);
}

void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if (event.type == sf::Event::TextEntered){
        if (event.text.unicode =='\b') {
            if(Userinput!=""){
                Userinput.erase((Userinput.size()-1),1);
            }

        }
        else {
            Userinput += static_cast<char>(event.text.unicode);
        }
    }
}
void TextInput::update(){
    input.setString(Userinput);

}

Snapshot& TextInput::getSnapshot(){

}
void TextInput::applySnapshot(const Snapshot& snapshot){

}
