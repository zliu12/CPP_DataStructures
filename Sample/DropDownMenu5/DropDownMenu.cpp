#include "DropDownMenu.h"

void DropDownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox);
    if (clicked){
        window.draw(list);
    }
}

void DropDownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if(mouseEvent.mouseClicked(inputBox,window)){

        clicked = true;
    }
    else if(mouseEvent.mouseClicked(window,event)){
        clicked = false;
    }
    list.addEventHandler(window, event);
    inputBox.setDisplayName(list.getClickedString());
    std::vector<Item>::iterator iter = list.vectorItem().begin();
    for(; iter != list.vectorItem().end(); ++iter){
        if (mouseEvent.mouseClicked(*iter, window)){
            displayString = list.getClickedString();
            History::pushHistory(getSnapshot());
            History::addComponent(displayString,this);
            clicked = false;
        }
    }

    History::addEventHandler(window,event);


}

void DropDownMenu::update() {
    applySnapshot(History::topHistory());
}

Snapshot &DropDownMenu::getSnapshot() {
    std::cout<<"getSnapshot!"<<std::endl;
    Snap.setString(displayString,displayString);
    return Snap;
}

void DropDownMenu::applySnapshot(const Snapshot &snapshot) {
    inputBox.setDisplayName(snapshot.getString());
//    std::cout<<"Ran!"<<std::endl;
//    std::cout<<"String in the snapshot: "<<snapshot.getString()<<std::endl;

}

DropDownMenu::DropDownMenu() {
    History::pushHistory(getSnapshot());
}
