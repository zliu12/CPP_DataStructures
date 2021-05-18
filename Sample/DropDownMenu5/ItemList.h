#ifndef PROJECT1_ITEMLIST_H
#define PROJECT1_ITEMLIST_H
#include "Item.h"
#include "MouseEvent.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <SFML/Graphics.hpp>

class ItemList: public Item {

private:
    std::string name;
    std::vector<Item> items;
    const float initialX = 0;
    const float initialY = 30;
    float newX = 0;
    float newY = 0; //current X and Y
    int n = 0;
    MouseEvent<Item> mouseEvent;
    Item item;
    Item item1;
    Item item2;
    Item item3;
    Item item4;
    bool clicked = false;



public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) ;
    virtual void update();


    ItemList();
    void AlignedItems();
    void addItem(Item newItem);
    void setPosition(sf::Vector2f position);
    void Resize(sf::Vector2f size);
    std::string getClickedString() const;
    bool ItemIsClicked();
    std::vector<Item>& vectorItem();
};


#endif //PROJECT1_ITEMLIST_H
