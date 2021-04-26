
#ifndef TextField_hpp
#define TextField_hpp
#include <SFML/Graphics.hpp>
#include "Word.hpp"
#include "list.h"

class TextField: public sf::Drawable, public sf::Transformable{
public:
    TextField();
    TextField(string sentence);
    void operator+=(string other);
    void add(string other);
    void pop_back();
    string getString();
    void reset(string other);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    bool empty();
    sf::FloatRect getLocalbounds();
    
private:
    string total;
    list<Word> words;    // list<sf::Text> words;   " hello world"   
    sf::Font font;
};

#endif /* TextField_hpp */
