
//std::stack<Node<History>> History::stack;
//
//Node<History>&  History::topHistory(){
//    return stack.top();
//}
//void History::pushHistory(const Node<History>& snapshot){
//    stack.push(snapshot);
//}
//void History::addEventHandler(sf::RenderWindow& window,sf::Event event){
//    if(KeyboardShortcut::isUndo()){
//        if(!stack.empty()){
//            stack.top().component->applySnapshot(stack.top().snapshot);
//            stack.pop();
//        }
//    }
//}

//void History::popHistory(){
//    stack.pop();
//}
//---------------------------------------------------------------------------
//void History::pushHistory(const Snapshot& snapshot)
//{
//    snapStack.push(snapshot);
//}
//Snapshot& History::topHistory()
//{
//    return snapStack.top();
//
//}
//void History::popHistory(){
//    snapStack.pop();
//}
//void History::addEventHandler(sf::RenderWindow& window, sf::Event event){
//    if(KeyboardShortcut::isUndo(event))
//    {
//        if(!snapStack.isEmpty())
//        {
//            snapStack.top().getData();
//        }
//    }
//}
//History::Response History::getComponent (std::string componentID){
//    Response r;
//    r.component = components[componentID];
//    r.found =true;
//
//}
//void History::addComponent(std::string componentID, GUIComponent* component){}

#include "History.h"
std::stack<Snapshot> History::stack;
std::map<std::string, GUIComponent*> History::components;
void History::pushHistory(const Snapshot& snapshot){
    stack.push(snapshot);
}
Snapshot& History::topHistory(){
    return stack.top();
}
void History::popHistory(){
    if(!stack.empty())
        stack.pop();
}
void History::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(KeyboardShortcut::isUndo(event)){
        if(stack.size()>1) {
            if (!stack.empty()) {
//                std::cout << "Last item in the stack: " << stack.top().getString() << std::endl;
                stack.pop();
//                std::cout << "After pop, stack ID: " << stack.top().getID() << std::endl;
//                std::cout << "After pop, stack string: " << stack.top().getString() << std::endl;
//            std::cout<<"Before pop, stack: "<<stack.top().getString()<<std::endl;
//            components[stack.top().getID()]->applySnapshot(stack.top());

//            if(!stack.empty()){
//                std::cout<<"After applySnapshot pop stack..."<<std::endl;
//                popHistory();
//            }
                std::cout << "stack size: " << stack.size() << std::endl;

            }
        }
    }

}
History::Response& History::getComponent(std::string componentID){
    Response r;
    std::map<std::string, GUIComponent*>::iterator iter = components.begin();
    for(; iter != components.end(); ++iter){
        if(iter->first == componentID){
            r.found = true;
            r.component = iter->second;
        }
    }
}
void History::addComponent(std::string componentID, GUIComponent* component){
    components[componentID] = component;
}

bool History::isStackEmpty(){
    return stack.empty();
}

int  History::stackSize(){
    return stack.size();
}
