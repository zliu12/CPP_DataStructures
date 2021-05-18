

#ifndef PROJECT1_STATES_H
#define PROJECT1_STATES_H
#include <map>
#include <vector>
#include "State.h"
#include <iostream>

enum ObjectState
{
    ENABLED,
    CURSORON,
    LASTSTATE,
    BLINKON,
};

class States {
private:
    std::map<ObjectState, bool>states;

public:
    States();
    bool checkState(ObjectState state) const;
    void enableState(ObjectState state);
    void disableState(ObjectState state);

};


#endif //PROJECT1_STATES_H
