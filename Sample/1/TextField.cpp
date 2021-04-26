
#include "TextField.hpp"


TextField::TextField()
: TextField(""){
    
}

TextField::TextField(string sentence){
    // "   hello  int 87erworld h"
    total = "";
    for(int i = 0; i < sentence.length(); ++i){
        add(to_string(sentence[i]));
    }
    if(!font.loadFromFile("OpenSans-Bold.ttf")){
        cout << "font is not loading\n";
    }
}

void TextField::operator+=(string other){
    add(other);
}

void TextField::add(string other){ // "hello  world"       list= H->["hello"]->["  world"]->   "hello  world"
    for(int i = 0; i < other.length(); ++i){
        string temp = "";
        temp += other[i];
        if(total.length() == 0){
            total += temp;
            Word word(temp);  // sf::Text
            int x = getPosition().x;
            word.setFont(font);
            word.setPosition(x, getPosition().y);
            words.insert_back(word);   // "hello world"     total = "he"
    
        }else if(total.back() != ' ' && temp == " "){  // "he"
            total += temp;
            Word word(temp);
            int x = words.last_node()->getPosition().x + words.last_node()->getLocalBounds().width + 10;
            word.setFont(font);
            word.setPosition(x, getPosition().y);
            words.insert_back(word);
            
        }else{
            total += temp;
            words.last_node()->add(temp);
        }
    }
}

void TextField::pop_back(){ 
    if(total.length() == 0){
        return;
    }else{
        total.pop_back();
        if(words.last_node()->empty())
            words.delete_node(words.last_node());
        words.last_node()->pop_back();
    }
    
}

string TextField::getString(){
    return total;
}

void TextField::reset(string other){
    total = "";
    while(words.begin()){
        words.delete_node(words.begin());
    }
    for(int i = 0; i < other.length(); ++i){
        string temp = "";
        temp += other[i];
        add(temp);
    }
}

bool TextField::empty(){
    return total.length()==0;
}


void TextField::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    for(list<Word>::Iterator it = words.begin(); it != words.end(); ++it){
        Word temp = *it;
        window.draw(temp);
    }
}

sf::FloatRect TextField::getLocalbounds(){
    sf::FloatRect rec;
    rec.top = getPosition().y;
    rec.left = getPosition().x;
    float width = 0;
    rec.height = words.begin()->getLocalBounds().height;
    for(list<Word>::Iterator it = words.begin(); it != words.end(); ++it){
        Word temp = *it;
        width += temp.getLocalBounds().width + 10;
    }
    rec.width = width;
    return rec;
}
