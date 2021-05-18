#ifndef PROJECT1_GUICOMPONENT_H
#define PROJECT1_GUICOMPONENT_H
#include "SFML/Graphics.hpp"
#include "SnapshotInterface.h"
#include "States.h"
#include "EventHandler.h"
#include <iostream>
class GUIComponent : public sf::Drawable, public SnapshotInterface, public States, public EventHandler, public sf::Transformable {
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //PROJECT1_GUICOMPONENT_H
