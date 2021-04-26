
#ifndef Typing_hpp
#define Typing_hpp
#include <iostream>

#include <SFML/Graphics.hpp>
#include "GUIComponent.hpp"
#include "TextField.hpp"
#include "History.hpp"
#include "KeyShortcuts.hpp"
#include "Cursor.hpp"



using namespace std;

class Typing: public GUIComponent{
public:
    Typing();
    void setPosition(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    
    void update();

    // from SnapshotInterface
    Snapshot& getSnapshot();
    void applySnapshot(const Snapshot& snapshot);
    
private:
    TextField field;
    Snapshot snap;
    Cursor cursor;
};

#endif /* Typing_hpp */
