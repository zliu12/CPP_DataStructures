#include "Typer.h"
Typer::Typer(){
}

void Typer::addEventHandler(sf::RenderWindow& window, sf::Event event){
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect boxSize = box.getBoxGlobal();
    if(!boxSize.contains(mpos))
    {
        sta = HIDDEN;
    }
       else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sta = NONHIDDEN;
            }
        }

    if(cursor.getCursorPosition().x > 527)
    {
        label.tooMuchletter();
    }
     if(KeyBoardShortCut::isUndo())
    {
         if(cursor.getCursorPosition().x>=63)
         {
             std::vector<sf::Color> colorTemp = inputtext.UndoCheckerColor(history);
             std::vector<char> charTemp = inputtext.UndoChecker(history);
             snapshot.resetSnapShot(charTemp, colorTemp);
         }
    }
    if (event.type == sf::Event::TextEntered ||sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
        if (event.text.unicode == '\b') {   // handle backspace explicitly
            history.pushHistory(snapshot);
            if(cursor.getCursorPosition().x>=63)
            {
                label.getNormal();
                inputtext.deleteStack();
                snapshot.removeChar();

            }
        }

        else if(event.type == sf::Event::TextEntered)
        {
            if(cursor.getCursorPosition().x < 527)
            {
                history.pushHistory(snapshot);
                ss = static_cast<char>(event.text.unicode);
                inputtext.setText(ss, key.KeyBoardColor(window,event));
                snapshot.insertChar(static_cast<char>(event.text.unicode), key.KeyBoardColor(window,event));
            }
        }
    }

}


void Typer::update(){
    inputtext.checker();
    cursor.update(sta);
   if(inputtext.getLinkedListSize() > 0){
       if(cursor.getCursorPosition().x < 550)
       {
           sf::Vector2f pos = inputtext.lastCharacterPos();
           cursor.updatePosition(pos);
       }
   }
   else
   {
       cursor.updatePosition({41,101});
   }
}

void Typer::draw(sf::RenderTarget& window, sf::RenderStates states) const{

        window.draw(label);
        window.draw(box);
        window.draw(inputtext);
        window.draw(cursor);
}
