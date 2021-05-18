#ifndef PROJECT1_LABEL_H
#define PROJECT1_LABEL_H
#include "SFML/Graphics.hpp"
#include <iostream>

class Label : public sf::Drawable {
public:
    Label();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

private:
    sf::Font font;
    sf::Text label;

};


#endif //PROJECT1_LABEL_H
