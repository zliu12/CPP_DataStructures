//
// Created by Rena on 4/10/21.
//

#ifndef PROJECTONETEXTBOX_BOX_H
#define PROJECTONETEXTBOX_BOX_H
#include <SFML/Graphics.hpp>

class Box : public sf::Drawable{
private:
    sf::RectangleShape rect;
public:
    Box();
    void setBoxSize();
    sf::Vector2f getBoxSize();
    sf::Vector2f getBoxPosition();
    sf::FloatRect getBoxGlobal();
    void setBoxBold();
    sf::RectangleShape getRect();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //PROJECTONETEXTBOX_BOX_H
