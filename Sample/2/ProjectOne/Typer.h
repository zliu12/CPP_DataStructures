#ifndef PROJECTONETEXTBOX_TYPER_H
#define PROJECTONETEXTBOX_TYPER_H
#include "TextInput.h"
#include "Label.h"
#include "Box.h"
#include "States.h"
#include "Cursor.h"
#include "TextInput.h"
#include "History.h"
#include "Snapshot.h"
#include "KeyBoardEvent.h"
#include "MouseEvents.h"
class Typer : public sf::Drawable{
private:
    Label label;
    Box box;
    KeyBoardEvent key;
    Cursor cursor;
    History history;
    Snapshot snapshot;
    TextInput inputtext;
    MouseEvents<sf::RectangleShape> mos;
    State sta;
    sf::String ss;


public:
    Typer();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;


};


#endif //PROJECTONETEXTBOX_TYPER_H
