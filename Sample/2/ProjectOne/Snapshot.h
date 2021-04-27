#ifndef PROJECTONETEXTBOX_SNAPSHOT_H
#define PROJECTONETEXTBOX_SNAPSHOT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LinkedList.h"
class Snapshot{
private:
public:
    std::vector<char> data;
    std::vector<sf::Color> cc;
    Snapshot();
    void insertChar(char c, sf::Color cc);
    void removeChar();
    void setLinkedList(LinkedList<sf::Text>text);
    Snapshot(std::string theData, sf::Color color);
    std::vector<sf::Color> applySnapshotColor(Snapshot& snapshot);
    void setColor(const sf::Color color);
    void resetSnapShot(std::vector<char> c, std::vector<sf::Color> color);
    //explicit Snapshot(std::string componentID);
    sf::Color getColor();

    friend std::ostream& operator << (std::ostream& out, const Snapshot& snapshot);
    // this function will apply a snapshot to the object.
    //This will revert the object back to the state that has been recorded in the snapshot
    std::vector<char> applySnapshot(const Snapshot& snapshot);
};


#endif //PROJECTONETEXTBOX_SNAPSHOT_H
