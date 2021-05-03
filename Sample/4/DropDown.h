#ifndef SFMLSET_DROPDOWN_H
#define SFMLSET_DROPDOWN_H

#include "Itemlist.h"
#include "InputBox.h"
// #include "GUIComponent.hpp"
#include "History.h"

class DropDown: public sf::Transformable, public sf::Drawable{
private:
    /* data */
    Itemlist menu;
    SnapShot snap;
    // InputBox box;
    InputBox input;
    float x, y;
public:
    DropDown();
    DropDown(vector<string> vec);  // given list of string
    
    // void resize(float x, float y);
    void setPosition(float x, float y);
    // void add(string item);
    // void remove(string item);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    
    SnapShot& getSnapShot();
    void applySnapshot(const SnapShot& snapshot);
};

#endif