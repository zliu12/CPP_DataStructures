//
// Created by yi yao on 3/18/21.
//
#ifndef SFMLSET_TYPING_CPP
#define SFMLSET_TYPING_CPP
#include "Typing.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void Typing::update(){
    // shot(text.getString());
    // cout << "Start Updata";
    // cout << list.Size() << endl;
    size = list.Size();
    Recursion(0);
    // cout << "typing Updata" << endl;
    // cout << "finish Updata" << endl;
}

void Typing::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    // cout << "Start Draw" << endl;
    for(int i = 0; i < size; i++){
        window.draw(list.target(i));
    }
    // cout << "Draw end" << endl;
}

void Typing::push(char s){
    text.setString(sf::String(s));
    if(isdigit(s)){
        text.setFillColor(sf::Color::Red);
        position.x += text.getLocalBounds().width;
        position.y = position.y;
    }else if(isalpha(s)){
        text.setFillColor(sf::Color::Yellow);
        position.x += 50.f;
        position.y = position.y;
    }else{
        text.setFillColor(sf::Color::Green);
        position.x += text.getLocalBounds().width;
        position.y = position.y;
    }
    text.setPosition(position);
    list.insertAfter(text);
    // text.setFillColor(sf::Color::Yellow);
    // cout << "finish input" << endl;
}

void Typing::pop(){
    list.RemoveTail(); 
    position = list.TAIL().getPosition();
}

void Typing::Recursion(int n){
    // cout << "Recursion used";
    if(n < size){
        if((n+3)< size){
            if(list.target(n).getString() == "i")
                if(list.target(n+1).getString() == "n")
                    if(list.target(n+2).getString() == "t"){
                        list.target(n).setFillColor(sf::Color::Blue);
                        list.target(n+1).setFillColor(sf::Color::Blue);
                        list.target(n+2).setFillColor(sf::Color::Blue);
                        Recursion(n+3);
                    }        
        }
        if((n+4)< size){
            if(list.target(n).getString() == "c")
                if(list.target(n+1).getString() == "h")
                    if(list.target(n+2).getString() == "a")
                        if(list.target(n+3).getString() == "r"){
                            list.target(n).setFillColor(sf::Color::Blue);
                            list.target(n+1).setFillColor(sf::Color::Blue);
                            list.target(n+2).setFillColor(sf::Color::Blue);
                            list.target(n+3).setFillColor(sf::Color::Blue);
                            Recursion(n+4);
                    }        
        }
        if((n+5)< size){
            if(list.target(n).getString() == "d")
                if(list.target(n+1).getString() == "o")
                    if(list.target(n+2).getString() == "u")
                        if(list.target(n+3).getString() == "b")
                            if(list.target(n+4).getString() == "l")
                                if(list.target(n+5).getString() == "e"){
                                    list.target(n).setFillColor(sf::Color::Blue);
                                    list.target(n+1).setFillColor(sf::Color::Blue);
                                    list.target(n+2).setFillColor(sf::Color::Blue);
                                    list.target(n+3).setFillColor(sf::Color::Blue);
                                    list.target(n+4).setFillColor(sf::Color::Blue);
                                    list.target(n+5).setFillColor(sf::Color::Blue);
                                    Recursion(n+6);
                                }
        }
        if((n+4)< size){
            if(list.target(n).getString() == "f")
                if(list.target(n+1).getString() == "l")
                    if(list.target(n+2).getString() == "o")
                        if(list.target(n+3).getString() == "a")
                            if(list.target(n+4).getString() == "t"){
                                    list.target(n).setFillColor(sf::Color::Blue);
                                    list.target(n+1).setFillColor(sf::Color::Blue);
                                    list.target(n+2).setFillColor(sf::Color::Blue);
                                    list.target(n+3).setFillColor(sf::Color::Blue);
                                    list.target(n+4).setFillColor(sf::Color::Blue);
                                    Recursion(n+5);
                                }
        }
        Recursion(n+1);
    }
    
}
#endif
