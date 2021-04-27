#include "TextInput.h"
TextInput::TextInput()
{
    x = 51;
    if(!font.loadFromFile("OpenSans-Bold.ttf"))
        exit(111);
    text.setFont(font);
    text.setCharacterSize(20);
    text.setPosition({51,101});
    text.setFillColor(sf::Color::White);
}
std::vector<char> TextInput::UndoChecker(History& history)
{
    snapshot = history.topHistory();
    std::vector<char> temp = snapshot.applySnapshot(snapshot);
    for(int i = 0 ; i < temp.size(); i ++ )
    {
        std::cout << i+1 << " "<< temp.at(i) <<std::endl;
    }
    resetStringwithSnapShot(snapshot);
    history.popHistory();
    return temp;
}
std::vector<sf::Color> TextInput::UndoCheckerColor(History& history)
{
    snapshot = history.topHistory();
    std::vector<sf::Color> temp = snapshot.applySnapshotColor(snapshot);
    return temp;
}
sf::Vector2f TextInput::lastCharacterPos()
{
    return t.at(t.size()-1).getPosition();
}

void TextInput::checker()
{
    if(t.size() >= 6)
    {
        for(int i = 0; i < t.size()-5; i++)
        {
            if(t.at(i).getString() == 'd')
                if(t.at(i+1).getString() == 'o')
                    if(t.at(i+2).getString() == 'u')
                        if(t.at(i+3).getString() == 'b')
                            if(t.at(i+4).getString() == 'l')
                                if(t.at(i+5).getString() == 'e')
                                {
                                    std::cout <<"yep" <<std::endl;
                                    t.seek(i).setFillColor(sf::Color::Blue);
                                    t.seek(i+1).setFillColor(sf::Color::Blue);
                                    t.seek(i+2).setFillColor(sf::Color::Blue);
                                    t.seek(i+3).setFillColor(sf::Color::Blue);
                                    t.seek(i+4).setFillColor(sf::Color::Blue);
                                    t.seek(i+5).setFillColor(sf::Color::Blue);
                                }
        }
    }
    if(t.size() >= 5)
    {
        for(int i = 0; i < t.size()-4; i++)
        {
            if(t.at(i).getString() == 'f')
                if(t.at(i+1).getString() == 'l')
                    if(t.at(i+2).getString() == 'o')
                        if(t.at(i+3).getString() == 'a')
                            if(t.at(i+4).getString() == 't')
                                {
                                    t.seek(i).setFillColor(sf::Color::Blue);
                                    t.seek(i+1).setFillColor(sf::Color::Blue);
                                    t.seek(i+2).setFillColor(sf::Color::Blue);
                                    t.seek(i+3).setFillColor(sf::Color::Blue);
                                    t.seek(i+4).setFillColor(sf::Color::Blue);
                                }
        }
    }
    if(t.size() >= 4)
    {
        for(int i = 0; i < t.size()-3; i++)
        {
            if(t.at(i).getString() == 'c')
                if(t.at(i+1).getString() == 'h')
                    if(t.at(i+2).getString() == 'a')
                        if(t.at(i+3).getString() == 'r')
                                {
                                    t.seek(i).setFillColor(sf::Color::Blue);
                                    t.seek(i+1).setFillColor(sf::Color::Blue);
                                    t.seek(i+2).setFillColor(sf::Color::Blue);
                                    t.seek(i+3).setFillColor(sf::Color::Blue);
                                }
        }
    }
    if(t.size() >= 3)
    {
        for(int i = 0; i < t.size()-2; i++)
        {
            if(t.at(i).getString() == 'i')
                if(t.at(i+1).getString() == 'n')
                    if(t.at(i+2).getString() == 't')
                                {
                                    t.seek(i).setFillColor(sf::Color::Blue);
                                    t.seek(i+1).setFillColor(sf::Color::Blue);
                                    t.seek(i+2).setFillColor(sf::Color::Blue);
                                }
        }
    }

}
int TextInput::getLinkedListSize()
{
    return t.size();
}

void TextInput::resetStringwithSnapShot(Snapshot& s)
{
         x = 51;
        std::vector<char> temp = snapshot.applySnapshot(s);
        std::vector<sf::Color> tempColor = snapshot.applySnapshotColor(s);

        if(temp.size() > 0)
        {
            t.deleteAllNode();
            for(int i = 0; i < temp.size(); i++)
            {
                sf::Text textTemp;
                if(!font.loadFromFile("OpenSans-Bold.ttf"))
                    exit(111);
                textTemp.setFont(font);
                textTemp.setString(temp.at(i));
                textTemp.setFillColor(tempColor.at(i));
                textTemp.setCharacterSize(20);
                textTemp.setPosition({x ,101});
                x+=10;
                t.insert(textTemp);
            }
        }
        else
            t.deleteAllNode();

}

sf::Vector2f TextInput::getTextPosition(int index)
{
        sf::Text temp = t.at(index);
        return temp.getPosition();
}
void TextInput::setText(sf::String s, sf::Color color)
{
    text.setString(s);
    text.setFillColor(color);
    text.setPosition(x , 101);
    x+=11;

    t.insert(text);
    std::cout << "size is " << t.getSize() <<std::endl;

}


void TextInput::deleteStack()
{
    if(t.size()>0) {
        std::cout << "size is " << t.getSize() <<std::endl;
        t.removeTail();
    }
    x-=10;
}


void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(int i = 0; i < t._size; i++)
    {
        window.draw(t.seek(i));
    }
}
History TextInput::popHistoryfromText()
{
    return history;
}
