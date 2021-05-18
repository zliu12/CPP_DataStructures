#ifndef PROJECT1_SNAPSHOT_H
#define PROJECT1_SNAPSHOT_H
#include <iostream>

class Snapshot {
private:
    std::string string,ID;

public:
    Snapshot();
    std::string getString() const;
    void setString(std::string s1, std::string ID);
    std::string getID() const;
};

#endif //PROJECT1_SNAPSHOT_H
