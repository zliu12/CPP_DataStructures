#ifndef PROJECT1_CHANGECOLOR_H
#define PROJECT1_CHANGECOLOR_H
#include <SFML/Graphics.hpp>
#include "Node_iterator.h"
#include "LinkedList.h"
#include <cctype>

class ChangeColor {
public:
    static void colorChange(LinkedList<sf::Text>::iterator& iter);


private:
    static bool iskeyWords(LinkedList<sf::Text>::iterator& iter);
    static int counter;
    static bool digit(LinkedList<sf::Text>::iterator& iter);
    static bool operators(LinkedList<sf::Text>::iterator& iter);
};


#endif //PROJECT1_CHANGECOLOR_H
