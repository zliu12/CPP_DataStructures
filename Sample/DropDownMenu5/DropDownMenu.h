#ifndef PROJECT1_DROPDOWNMENU_H
#define PROJECT1_DROPDOWNMENU_H
#include "GUIComponent.h"
#include "InputBox.h"
#include "ItemList.h"
#include "History.h"
class DropDownMenu : public GUIComponent{
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    DropDownMenu();

private:
    InputBox inputBox;
    ItemList list;
    std::string displayString;
    Snapshot Snap;
    MouseEvent<Item> mouseEvent;
    bool clicked = false;
};


#endif //PROJECT1_DROPDOWNMENU_H
