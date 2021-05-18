#ifndef PROJECT1_TEXTBOX_H
#define PROJECT1_TEXTBOX_H
#include "GUIComponent.h"
class Textbox : public GUIComponent{
public:
    Textbox();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::Vector2f getPosition();
    sf::Rect<float> getLocalBounds();

private:
    sf::RectangleShape textbox;
    int n = 15;

    const float WIDTH = 300;
    const float HEIGHT = 30;
    const float x = 102;
    const float y = 204;
};


#endif //PROJECT1_TEXTBOX_H
