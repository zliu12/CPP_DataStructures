
#ifndef Word_hpp
#define Word_hpp
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Word: public sf::Text{ 
public:
    Word(string words, sf::Color color, int size);
    Word(string words, int size);
    Word(string words);
    Word();
    void update();
    void pop_back();
    void operator+=(string other);
    bool empty();
    void add(string other);
    friend bool operator==(const Word& first, const Word& second);
    
    
private:
    int size;
};

#endif /* Word_hpp */
