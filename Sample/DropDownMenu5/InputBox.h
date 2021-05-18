#ifndef PROJECT1_INPUTBOX_H
#define PROJECT1_INPUTBOX_H
#include "Textbox.h"
#include "Item.h"

class InputBox : public Item{
public:

    InputBox();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::Vector2f getPosition();
    sf::Rect<float> getLocalBounds();

    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    bool isClicked() const;

private:
    sf::RectangleShape inputBox;
    sf::Text text;
    const float HEIGHT = 28;
    const float WIDTH = 200;
    sf::Vector2f defaultSize = {WIDTH, HEIGHT};
    const float x = 0;
    const float y = 0;
    sf::Vector2f defaultPosition = {x,y};
    Item item;
    MouseEvent<Item> mouseEvent;
    bool clicked = false;

};


#endif //PROJECT1_INPUTBOX_H
