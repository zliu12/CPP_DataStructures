
#include "Typing.hpp"


Typing::Typing(){

}

void Typing::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(field);
    if(!States::isStateEnabled(States::HIDDEN))
        window.draw(cursor);
}


void Typing::update(){
    if(field.empty())
        cursor.setPosition(field.getPosition().x, field.getPosition().y+15);
    else
        cursor.setPosition(field.getPosition().x + field.getLocalbounds().width - 2, field.getPosition().y+15);
    
    cursor.update();
}

void Typing::setPosition(float x, float y){
    field.setPosition(x, y);
    cursor.setPosition(x+5, y);
}


void Typing::addEventHandler(sf::RenderWindow& window, sf::Event event){
//    bool back = false;
//    bool text = false;
//    string a = "";
    if(States::isStateEnabled(States::HIDDEN))
        return;
    if(KeyShortcuts::isUndo()){
        if(!field.empty()){
            applySnapshot(History::topHistory());
            History::popHistory();
        }
    }else if(event.type == sf::Event::TextEntered){
        if(event.text.unicode == 8){
            History::pushHistory(getSnapshot());
            field.pop_back();
//            back = true;
            cout << "pop2 string = " << field.getString() << endl;

        }else if(event.text.unicode < 128){
            char temp = static_cast<char>(event.text.unicode);
            History::pushHistory(getSnapshot());
            string a = "";
            a += temp;
            field += a;
//            text = true;
            cout << "string = " << field.getString() << endl;
        }
    }
    

//    if(event.type == sf::Event::KeyPressed){
//        if (event.key.code == sf::Keyboard::Backspace){
//            contents.pop_back();
//            cout << "pop2 string = " << contents << endl;
//        }
//    }
}

Snapshot& Typing::getSnapshot(){
    snap.setString(field.getString());
    return snap;
}


void Typing::applySnapshot(const Snapshot& snapshot){
    string other = snapshot.getData();
    //cout << "reset: " << other << endl;
    field.reset(other);
}
