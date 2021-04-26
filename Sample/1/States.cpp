
#include "States.hpp"

std::map<States::ObjectState, bool> States::states;

States::States(){
    for(int i = static_cast<int>(HIDDEN); i < static_cast<int>(LASTSTATE); i++){
        states[static_cast<ObjectState>(i)] = false;
    }

}
bool States::isStateEnabled(ObjectState state){
    return states[state];
}


void States::setStateEnable(ObjectState state, bool set){
    states[state] = set;
}
