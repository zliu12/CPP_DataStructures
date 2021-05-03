#ifndef SFMLSET_ITEMLIST_H
#define SFMLSET_ITEMLIST_H
#include <iostream>
// #include <SFML/Graphics.hpp>
#include "Item.h"
#include "LinkedList.h"
#include "MouseEvent.h"
#include "State.h"

class Itemlist: public sf::Transformable, public sf::Drawable{
private:
    /* data */
    LinkedList<Item> list;
    int size;
    string chose;
    float y;
public:
    Itemlist(/* args */);
    Itemlist(vector<string> vector);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void Insert(sf::String i);
    string getClicked();

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
};

#endif


