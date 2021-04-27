#include "Label.h"
Label::Label()
{
    l = "Please Test the Program" ;
    setLabel(l);
    setLabelSize(20);
    setLabelPosition({130,40});

}
void Label::getNormal()
{
    text1.setString("");
}

void Label::setLabel(std::string a)
{
    l = a;
    text.setFillColor(sf::Color::Blue);
    if(!font.loadFromFile("OpenSans-Bold.ttf"))
        exit(1);
    text.setFont(font);
    text.setCharacterSize(size);
    text.setString(l);
    text1.setFont(font);
    text1.setCharacterSize(20);
    text1.setPosition({100,200});
    text1.setFillColor(sf::Color::Yellow);
}

void Label::setLabelSize(int size)
{
    this->size = size;
    text.setCharacterSize(size);
}

void Label::setLabelPosition(sf::Vector2f pos)
{
    text.setPosition(pos);
}
void Label::tooMuchletter()
{
    text1.setString("You enter too much ! \n"
                    "Delete something to keep testing!");
}

void Label::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(text);
    window.draw(text1);
}
