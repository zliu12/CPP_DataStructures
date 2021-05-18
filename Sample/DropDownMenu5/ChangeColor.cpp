#include "ChangeColor.h"

int ChangeColor::counter = 0;

void ChangeColor::colorChange(LinkedList<sf::Text>::iterator& iter){

    int i = 0;


    if(digit(iter))
    {
        (*iter).setFillColor(sf::Color::Red);
    }
    else if(operators(iter))
    {
        (*iter).setFillColor(sf::Color::Green);
    }
    else if ( iskeyWords(iter)&& counter != 0) {
        while (counter!=0){
            (*(iter+i)).setFillColor(sf::Color::Blue);
            i++;
            counter--;
        }

    }
    else{
        return;
    }
}

bool ChangeColor::digit(LinkedList<sf::Text>::iterator &iter) {
    char temp=(char)(*iter).getString()[0];
    return(isdigit(temp));
}

bool ChangeColor::operators(LinkedList<sf::Text>::iterator &iter) {
    char temp = (char)(*iter).getString()[0];
   // cout<<"temp: "<<temp<<endl;
    return (temp == '+' || temp == '-' || temp == '*' || temp == '='
            || temp == '/'||temp == '<' || temp =='>');
}

bool ChangeColor::iskeyWords(LinkedList<sf::Text>::iterator& iter){
    char temp1 = (char)(*iter).getString()[0];
    char temp2 = (char)(*(iter+1)).getString()[0];
    char temp3 = (char)(*(iter+2)).getString()[0];
    char temp4 = (char)(*(iter+3)).getString()[0];
    char temp5 = (char)(*(iter+4)).getString()[0];
    char temp6 = (char)(*(iter+5)).getString()[0];

    if(temp1 == 'i' && temp2 == 'n' && temp3 == 't'){
        counter = 3;
        return true;
    }
    else if(temp1 =='f' && temp2 == 'o' && temp3 == 'r'){
        counter = 3;
        return true;
    }
    else if(temp1 == 'b' && temp2 == 'o' && temp3 == 'o' && temp4 == 'l'){

        counter = 4;
        return true;
    }
    else if(temp1 == 'c' && temp2 == 'h' && temp3 == 'a' && temp4 == 'r'){

        counter = 4;
        return true;
    }
    else if(temp1 == 'f' && temp2 == 'l' && temp3 == 'o' && temp4 == 'a' && temp5 =='t'){

        counter = 5;
        return true;
    }
    else if(temp1 == 's' && temp2 == 't' && temp3 == 'r' && temp4 == 'i' && temp5 =='n'&& temp6 == 'g'){

        counter = 6;
        return true;
    }
    else if(temp1 == 'd' && temp2 == 'o' && temp3 == 'u' && temp4 == 'b' && temp5 =='l'&& temp6 == 'e'){

        counter = 6;
        return true;
    }
    else{
        return false;
    }
}