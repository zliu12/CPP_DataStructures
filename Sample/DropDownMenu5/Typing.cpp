#include "Typing.h"

Typing::Typing(){
    if (!font.loadFromFile("OpenSans-Bold.ttf")){
        std::cout<<"Can not open the font file"<<std::endl;
    }
    object.setFont(font);
    object.setCharacterSize(18);
    object.setPosition(typeInputX,typeInputY);
    object.setFillColor(sf::Color::White);

}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    cursor.addEventHandler(window,event);

    if(cursor.checkState(CURSORON)) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b') { //backspace
                if (Userinput != "") {
                    Userinput.erase((Userinput.size() - 1), 1);
                }
            } else {
                Userinput += static_cast<char>(event.text.unicode);
                std::cout<<Userinput<<std::endl;
            }

            MulText.pushBack(Userinput, object);
        } else if (event.key.code == sf::Keyboard::Enter) {

            setPosition(x,y+n);
            n+=15;
        }

    }
    cursor.set_Position({get_Position().x,get_Position().y});

}

void Typing::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    if(cursor.checkState(BLINKON))
    {
        window.draw(cursor);
    }
    window.draw(MulText);
}

void Typing::update() {

//    object.setString(Userinput);
//
    MulText.update();
    cursor.update();


}
sf::Vector2f Typing::get_Position()
{
    return MulText.getBound(object);

}