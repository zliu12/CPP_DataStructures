
#include "Snapshot.hpp"


Snapshot::Snapshot(std::string data){
    this->data = data;
}


std::string Snapshot::getData() const{
    return data;
}

void Snapshot::setString(std::string other){
    data = other;
    std::cout << "Snapshot-setString(): " << other << std::endl;
}
