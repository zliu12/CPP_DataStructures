#include "Snapshot.h"
Snapshot::Snapshot()
{

}
void Snapshot::resetSnapShot(std::vector<char> c, std::vector<sf::Color> color)
{
    data.clear();
    cc.clear();
    if(c.size() > 0) {
        for (int i = 0; i < c.size(); i++) {
            char temp = c.at(i);
            sf::Color tempColor = color.at(i);
            insertChar(temp, tempColor);
        }
    }
}

void Snapshot::insertChar(char c, sf::Color color)
{
    data.push_back(c);
    cc.push_back(color);
}
void Snapshot::removeChar()
{
    if(data.size() > 1 )
    {
        int ss =data.size();
        data.erase(data.begin()+ss-1);
        cc.erase(cc.begin()+ss-1);
    }
}

// this function will apply a snapshot to the object.
//This will revert the object back to the state that has been recorded in the snapshot
std::vector<char> Snapshot::applySnapshot(const Snapshot& snapshot)
{
    return snapshot.data;
}
std::vector<sf::Color> Snapshot::applySnapshotColor(Snapshot& snapshot)
{
    return snapshot.cc;
}

//void Snapshot::setData(const std::string& data)
//{
//    this->data = data;
//}

//std::string Snapshot::getData()
//{
//    return data;
////}
//std::ostream& operator << (std::ostream& out, const Snapshot& snapshot)
//{
//    std::cout << snapshot.data <<std::endl;
//}