#ifndef PROJECT1_HISTORY_H
#define PROJECT1_HISTORY_H
#include <stack>
#include "LinkedList.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "KeyboardShortcut.h"
#include "Snapshot.h"
#include "GUIComponent.h"
//#include "Stack.h"

//class History {
//private:
//    static std::stack<Node<History>> stack;
//public:
//    static Node<History>& topHistory();
//    static void pushHistory(const Node<History>& snapshot);
//    static void popHistory();
//    static void addEventHandler(sf::RenderWindow& window,sf::Event event);
//};

class History  {
private:
    static std::stack<Snapshot> stack;
    static std::map<std::string, GUIComponent*> components;
public:
    struct Response{
        bool found = false;
        GUIComponent* component;
    };
    static void pushHistory(const Snapshot& snapshot);
    static Snapshot& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static Response& getComponent(std::string componentID);
    static void addComponent(std::string componentID, GUIComponent* component);
    static bool isStackEmpty();
    static int stackSize();

};
#endif //PROJECT1_HISTORY_H
