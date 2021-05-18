#include "ItemList.h"

ItemList::ItemList() {
//    Item item1;
//    item1.setDisplayName("Hello");
////    item1.setPosition({200,200});
//    items.push_back(&item1);

    item.setDisplayName("Hello world");
    items.push_back(item);
    item1.setDisplayName("Hello");
    items.push_back(item1);
    item2.setDisplayName("Apple");
    items.push_back(item2);
    item3.setDisplayName("Great");
    items.push_back(item3);


    AlignedItems();


}

void ItemList::AlignedItems() {
    std::vector<Item>::iterator iter;
    for(iter = items.begin();iter != items.end(); ++iter){
        (*iter).setPosition({initialX,initialY+n});
        n += 32;
    }
    newY = initialY + n;
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    for (int i=0;i<items.size(); i++){
        window.draw(items.at(i));
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    std::vector<Item>::iterator iter = items.begin();
    for(;iter != items.end(); ++iter) {
        if (mouseEvent.mouseClicked(*iter, window)) {
            name = (*iter).getString();
            clicked = true;
        }
        (*iter).addEventHandler(window,event);
    }

}

void ItemList::update() {

}

std::string ItemList::getClickedString() const{
    return name;
};




void ItemList::addItem(Item newItem) {
    items.push_back(newItem);
    newItem.setPosition({initialX, newY});
    n += 25;
}

void ItemList::setPosition(sf::Vector2f position) {
   item.setPosition(position);
   AlignedItems();
}

void ItemList::Resize(sf::Vector2f size) {
    std::vector<Item>::iterator iter = items.begin();
    for(; iter != items.end(); ++iter){
        (*iter).setSize(size);
    }
    AlignedItems();
   // item.setSize(size);
}

bool ItemList::ItemIsClicked(){
    return clicked;
}

std::vector<Item>& ItemList::vectorItem() {
    return items;
}
