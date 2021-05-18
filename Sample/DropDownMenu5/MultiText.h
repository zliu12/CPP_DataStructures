#ifndef PROJECT1_MULTITEXT_H
#define PROJECT1_MULTITEXT_H


#include "LinkedList.h"
#include "GUIComponent.h"
#include "ChangeColor.h"

class MultiText: public GUIComponent {

public:
    MultiText();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const ;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) ;
    virtual void update() ;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot) ;
    void pushBack(char data,sf::Text input); // where the position the data are
    void pushBack(std::string dataString, sf::Text input); //sending data to the list of the string
    sf::Vector2f getBound(sf::Text input);

private:

    LinkedList<sf::Text> text;
    sf::Text type;
    sf::Font font;
    const float Height  = 208;

};


#endif //PROJECT1_MULTITEXT_H
