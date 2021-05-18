#include "iostream"
#include "EventHandler.h"
#include "SFML/Graphics.hpp"
#include "TextInput.h"
#include "Label.h"
#include "Textbox.h"
#include "Typing.h"
#include <cctype>
#include "Cursor.h"
#include "ItemList.h"
#include "InputBox.h"
#include "DropDownMenu.h"
#include <stack>
using namespace std;

int main(){
    sf::RenderWindow window(sf:: VideoMode(500,500,32),"Typing Box");
//    sf::Cursor cursor;
//    if(cursor.loadFromSystem(sf::Cursor::Text))
//        window.setMouseCursor(cursor);

//    Textbox box;
//    Label label;
//    Typing input;
    //Cursor cursor;
//    ItemList list;
//    InputBox inputBox;

    DropDownMenu Menu;
//    list.addItem("yes");
//    Item item("hello");

//std::stack<int> s;
//
//for(int i=0;i<10;i++)
//    s.push(i);
//
//
//std::cout<<"Size: "<<s.size()<<std::endl;
//std::cout<<"Top: "<<s.top()<<std::endl;






    while(window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                window.close();
//            input.addEventHandler(window,e);
//////            sf::Vector2f position = input.get_Position();
//////            cursor.set_Position(position);
//////            cursor.addEventHandler(window,e);
//            box.addEventHandler(window,e);
//                list.addEventHandler(window,e);
//                inputBox.addEventHandler(window,e);
            Menu.addEventHandler(window,e);





        }
        window.clear();
        Menu.update();
//        input.update();
//        window.draw(box);
//        window.draw(label);
//        window.draw(input);

//        window.draw(list);
////        window.draw(item);
//        window.draw(inputBox);
        window.draw(Menu);
        window.display();
    }

//    if(isdigit('1')){
//        cout<<"it is digit."<<endl;
//
//    }
//    else{
//        cout<<"Not digit"<<endl;
//    }

//    char str[] = "hj;pq910js4";
//
//    cout << "The digit in the string are:" << endl;
//    for (int i=0; i<strlen(str); i++)
//    {
//        if (isdigit(str[i]))
//            cout << str[i] << " ";
//    }

}


