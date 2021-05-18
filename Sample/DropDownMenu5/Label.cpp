#include "Label.h"
Label::Label(){
    if (!font.loadFromFile("OpenSans-Bold.ttf")){
        std::cout<<"Can not open the font file"<<std::endl;
    }
    label.setFont(font);
    label.setString("Text Input: ");
    label.setCharacterSize(20);
    label.setFillColor(sf::Color::White);
    //label.setStyle(sf::Text::Bold);
    label.setPosition(sf::Vector2f(50,150));

}
void Label::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(label);
}