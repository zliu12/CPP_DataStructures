#ifndef PROJECTONETEXTBOX_GUICOMPONENTS_H
#define PROJECTONETEXTBOX_GUICOMPONENTS_H
#include "KeyBoardShortCut.h"
#include "SnapshotInterface.h"
#include "States.h"
class GUIComponents : public KeyBoardShortCut, public SnapshotInterface,
public States, public sf::Drawable{
//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
    virtual void applySnapShot(const Snapshot& snapshot) = 0;
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //PROJECTONETEXTBOX_GUICOMPONENTS_H
