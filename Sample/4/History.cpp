#include "History.h"

Stacks<SnapShot> History::stack;

History::History(){
//    Snapshot snap;
//    this->pushHistory(snap);
}

void History::pushHistory(const SnapShot& snapshot){
    stack.push(snapshot);
}

SnapShot History::topHistory(){
    if(stack.empty()){
        SnapShot temp("");
        return temp;
    }
    return stack.top();
}

void History::popHistory(){
    stack.pop();
}

void History::addEventHandler(sf::RenderWindow& window, sf::Event event){

}

bool History::isEmpty(){
    return stack.empty();
}