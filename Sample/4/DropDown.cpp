
#include "DropDown.h"

DropDown::DropDown(): DropDown(vector<string>{"Something"}){}


DropDown::DropDown(vector<string> vec){
    x = 0;
    y = 0;
    input.setPosition(x, y);
    input.setText(vec.at(0));
    menu.setPosition(0, input.getLocalBounds().height + 5);

    for(int i = 0; i < vec.size(); i++){
        menu.Insert(vec.at(i));
    }
}

void DropDown::draw(sf::RenderTarget& window, sf::RenderStates State) const{
    window.draw(input);
    if(State::isStateEnabled(State::APPEAR))
        window.draw(menu);
}

void DropDown::addEventHandler(sf::RenderWindow& window, sf::Event event){
    // undo key
    if(
        ( sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem) )&&
        ( sf::Keyboard::isKeyPressed(sf::Keyboard::Z) )
       ){
        if(History::topHistory().getSnapshot() != ""){
            applySnapshot(History::topHistory());
            History::popHistory();
        }
    }
    
    
    if(MouseEvents<InputBox>::mouseClicked(input, window)){
        // cout << State::APPEAR << endl;
        if(State::isStateEnabled(State::APPEAR)){
            State::setStateEnable(State::APPEAR, false);
            // cout << State::APPEAR << endl;
        }
        else
            State::setStateEnable(State::APPEAR, true);

        // cout << State::APPEAR << endl;
    }
    
    if(State::isStateEnabled(State::APPEAR)){
        // cout << State::APPEAR << endl;
        menu.addEventHandler(window, event);
    }
}


void DropDown::update(){
    if(State::isStateEnabled(State::CLICKED)){
        History::pushHistory(getSnapShot());
        State::setStateEnable(State::CLICKED, false);
        input.setText(menu.getClicked());
        setPosition(x, y);
    }
}

void DropDown::setPosition(float x, float y){
    this->x = x;
    this->y = y;
    input.setPosition(x, y);
    menu.setPosition(x, y + input.getLocalBounds().height + 5);
}

SnapShot& DropDown::getSnapShot(){
    snap.setString(input.getText());
    return snap;
}


void DropDown::applySnapshot(const SnapShot& snapshot){
    string other = snapshot.getSnapshot();
    input.setText(other);
    setPosition(x, y);
}

