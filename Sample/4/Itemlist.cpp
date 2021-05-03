
#include "Itemlist.h"

Itemlist::Itemlist(){
    y = 0.f;
    size = list.Size();
}

Itemlist::Itemlist(vector<string> vector){
    for(int i = 0; i < vector.size(); ++i){
        Insert(vector.at(i));
    }
    size = list.Size();
};

void Itemlist::Insert(sf::String i){
    Item item;
    item.String(i);
    y += 100.f;
    item.Position(0.f, y);

    list.insertAfter(item);
}

void Itemlist::addEventHandler(sf::RenderWindow& window, sf::Event event){
    LinkedList<Item>::iterator iter = list.begin();

    for(; iter != list.end(); ++iter){
        if(MouseEvents<Item>::hovered(*iter, window)){
            iter.current->data.setColor(sf::Color::Blue);
            string data = iter.current->data.getString();
            // cout << data << endl;
        }else{
            iter.current->data.setColor(sf::Color::Transparent);
        }
        
        if(MouseEvents<Item>::mouseClicked(*iter, window)){
            // if mouse clicked on an option, closed the bar
            // set clicked state to be true
            State::setStateEnable(State::APPEAR, false);
            State::setStateEnable(State::CLICKED, true);
            chose = iter.current->data.getString();
            cout << chose << endl;
        }
    }
}

void Itemlist::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    LinkedList<Item> ::iterator iter = list.begin();
    for(;iter != list.end(); ++iter){
        window.draw(*iter);
    }
}

string Itemlist::getClicked(){
    return chose;
}