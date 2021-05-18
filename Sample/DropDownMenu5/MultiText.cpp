#include "MultiText.h"
MultiText::MultiText()
{
    if (!font.loadFromFile("OpenSans-Bold.ttf")){
        std::cout<<"Can not open the font file"<<std::endl;
    }
    type.setFont(font);
    type.setFillColor(sf::Color::White);
    type.setCharacterSize(18);
}

void MultiText::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    LinkedList<sf::Text>::iterator iter;

    for(iter=text.begin(); iter!=text.end(); ++iter)
    {
        window.draw(*iter);
    }
}


void MultiText::addEventHandler(sf::RenderWindow& window, sf::Event event)
{


}

void MultiText::update()
{
    LinkedList<sf::Text>::iterator iter;
    for(iter=text.begin(); iter!=text.end(); ++iter)
    {
        ChangeColor::colorChange(iter);
    }

}

Snapshot& MultiText::getSnapshot()
{
}
void MultiText::applySnapshot(const Snapshot& snapshot)
{
}

void MultiText::pushBack(char data, sf::Text input)
{
    type.setString(std::string(1, data));
    LinkedList<sf::Text>::iterator iter;

    iter = text.Rbegin();
    if(text.isEmpty())
    {
        type.setPosition(105,Height);
    } else
    {
        type.setPosition((*iter).getGlobalBounds().left +(*iter).getGlobalBounds().width,input.getPosition().y );

    }
    text.insertTail(type);

}
void MultiText::pushBack(std::string dataString, sf::Text input)
{
    text.clear();
    for(int i=0; i<dataString.size(); i++)
    {
        pushBack(dataString[i], input);
    }

}

sf::Vector2f MultiText::getBound(sf::Text input)
{
    sf::Vector2f bound;
    if(!text.isEmpty())
    {
        bound.x= text.getTail().getGlobalBounds().left + text.getTail().getLocalBounds().width;
        bound.y= input.getPosition().y;
        return bound;
    }
    else
        return {105,Height};
}