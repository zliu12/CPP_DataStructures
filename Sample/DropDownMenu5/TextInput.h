#ifndef PROJECT1_TEXTINPUT_H
#define PROJECT1_TEXTINPUT_H
#include "SFML/Graphics.hpp"
#include "GUIComponent.h"
#include "Textbox.h"
class TextInput: public GUIComponent{
private:
    sf::Text input;
    sf::Font font;
    std::string Userinput = "";
public:
    TextInput();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //PROJECT1_TEXTINPUT_H
