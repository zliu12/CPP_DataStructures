#ifndef PROJECTONETEXTBOX_TEXTINPUT_H
#define PROJECTONETEXTBOX_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>
#include <iostream>
#include "Snapshot.h"
#include "History.h"
#include <vector>
#include "LinkedList.h"
class TextInput:public sf::Drawable{
private:
    sf::Text text;
    sf::Font font;
    Snapshot snapshot;
    LinkedList<sf::Text> t;
    History history;
    float x;
    const float y =100;


public:
    TextInput();
    void setText(sf::String s, sf::Color color);
    sf::Vector2f getTextPosition(int index);
    void deleteStack();
    void checker();
    int getLinkedListSize();
    History popHistoryfromText();
    void resetStringwithSnapShot(Snapshot& s);
    std::vector<char> UndoChecker(History& history);
    std::vector<sf::Color> UndoCheckerColor(History& history);
    sf::Vector2f lastCharacterPos();
    void addColorText(sf::String s, sf::Color color);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //PROJECTONETEXTBOX_TEXTINPUT_H
