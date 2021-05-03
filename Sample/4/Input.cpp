
#ifndef SFMLSET_INPUT_CPP
#define SFMLSET_INPUT_CPP
#include "Input.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


void Input::addEventHandler(sf::RenderWindow& window, sf::Event event){
    // typing.addEventHandler(window,event);
    // !TyperSnapshot t = getSnapShot();
    // texts.addEvenrHandle(window, event);
    if (event.type == sf::Event::TextEntered)
    {
        // !TyperSnapshot t = getSnapShot();
        // std::string s = text.getString().toAnsiString();
        if(event.text.unicode == '\b'){
            typing.pop();
        }
        else if(event.text.unicode == '\n'){
            typing.Enter();
        }
        else if (event.text.unicode < 128 ){
            texting = static_cast<char>(event.text.unicode);
            typing.push(texting);
            // cout << "Text creat sucessful" << endl;
        }
    }
        // History::pushHistory(t);
}

void Input::update(){
    // cout << "Start Updata" << endl;
    typing.update();
    position = typing.GetPosition();
    position.x = typing.width() + 50.f;
    // position.y = typing.height() + 250.f;
    // cout << "Cursor update" << endl;
    cursor.update(position);
    // cursor.setPosition(position);
    if(typing.GetPosition().x > (box.Size().width) || typing.GetPosition().y > (box.Size().height+150))
    {
        title.tooMuchletter("Out of Box");
    }else{
        title.tooMuchletter("");
    }
}
void Input::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(title,states);
    window.draw(box,states);
    window.draw(cursor,states);
    window.draw(typing,states);
}
#endif
