
#include "Word.hpp"


Word::Word(string words, sf::Color color, int size){
    this->size = size;
    setString(words);
    setFillColor(color);
    setCharacterSize(size);
    update();
}


Word::Word(string words, int size)
: Word(words, sf::Color::White, size){
    
}


Word::Word(string words)
: Word(words, sf::Color::White, 60){
    
}


Word::Word()
: Word("", sf::Color::White, 60){
    
}

void Word::update(){
    string word = getString();
    word.erase( remove(word.begin(), word.end(), ' ') );
    
    bool number = true;
    bool ope = true;
    for(int i = 0; i < word.length(); ++i){
        if(!isdigit(word[i])){
            number = false;
        }
        string temp = "";
        temp += word[i];
        if(temp != "=" && temp != "<" && temp != ">" &&
           temp != "+" && temp != "-" && temp != "!" &&
           temp != "*" && temp != "/" && temp != "%" ){
            ope = false;
        }
    }
    
    if(word == "int" || word == "double" ||
       word == "float" || word == "char"){
        setFillColor(sf::Color::Blue);
    }else if(number)
        setFillColor(sf::Color::Red);
    else if(ope)
        setFillColor(sf::Color::Green);
    else
        setFillColor(sf::Color::White);
}

void Word::pop_back(){
    string temp = getString();
    if(temp.length() == 1)
        temp = "";
    else
        temp.pop_back();
    setString(temp);
    update();
}

void Word::operator+=(string other){
    add(other);
    update();
}

void Word::add(string other){
    string temp = getString();
    temp += other;
    setString(temp);
    update();
}

bool Word::empty(){
    string temp = getString();
    return temp.length() == 0;
}

bool operator==(const Word& first, const Word& second){
    return (first.getString() == second.getString());
}


