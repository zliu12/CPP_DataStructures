
#include "Snapshot.h"
std::string Snapshot::getString() const{
    return string;
}

void Snapshot::setString(std::string s1, std::string ID) {
    string = s1;
    this->ID = ID;
}

std::string Snapshot::getID() const {
    return ID;
}

Snapshot::Snapshot(){}