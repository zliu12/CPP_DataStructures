#include "Cursor.h"
Cursor::Cursor()
{
    if (!font.loadFromFile("OpenSans-Bold.ttf")){
        std::cout<<"Can not open the font file"<<std::endl;
    }
    cursor.setFont(font);
    cursor.setString("|");
    cursor.setFillColor(sf::Color::White);
    cursor.setCharacterSize(18);
    cursor.setPosition({105,208});
    disableState(CURSORON);

}

void Cursor::blinking()
{
    if (checkState(CURSORON)) {
        if (checkState(BLINKON)) {
            disableState(BLINKON);
        } else {
            enableState(BLINKON);
        }
    }else{
        disableState(BLINKON);
    }

}


void Cursor::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
        window.draw(cursor);

}

void Cursor::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

    if(mouseEvent.mouseClicked(textbox, window)){
        enableState(CURSORON);
        //text.addEventHandler(window,event);
        //set_Position();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        cursor.setPosition({105, 250});
    }
//    else {
//        disableState(CURSORON);
//    }
    else if (mouseEvent.mouseClicked(window,event)){
        disableState(CURSORON);
    }
}
void Cursor::update()
{
    if (clock.getElapsedTime().asMilliseconds() > 500) {
        blinking();
        clock.restart();
    }

   // text.update();
}


Snapshot& Cursor::getSnapshot(){}
void Cursor::applySnapshot(const Snapshot& snapshot)
{

}

//void Cursor::set_Position()
//{
//   // sf::Vector2f position =  text.get_Position();
//    cursor.setPosition(position.x, position.y);
//    std::cout<<"y: "<<position.y<<std::endl;
//    std::cout<<"x: "<<position.x<<std::endl;
//}

void Cursor::set_Position(sf::Vector2f position)
{
    // sf::Vector2f position =  text.get_Position();
    cursor.setPosition(position.x, position.y);
    std::cout<<"y: "<<position.y<<std::endl;
    std::cout<<"x: "<<position.x<<std::endl;
}
