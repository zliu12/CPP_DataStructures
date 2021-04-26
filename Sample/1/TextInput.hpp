
#ifndef TextInput_hpp
#define TextInput_hpp
#include <SFML/Graphics.hpp>
#include "TextInputBox.hpp"
#include "Typing.hpp"
#include "MouseEvents.hpp"


class TextInput: public sf::Drawable, public sf::Transformable{
public:
    TextInput();
    
    
    void setLabel(string word);
    void setLabelSize(int size);
    
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    
private:
    TextInputBox textBox;
    Typing typing;
    Word label;
    sf::Font font;
};

#endif /* TextInput_hpp */
