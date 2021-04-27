#include "States.h"
//
//States::States()
//{
//    for(int i = 0; i < State::LASTSTATE; i++)
//    {
//        states[(State)i] = false;
//    }
//}
//States::States(std::vector<States> states) : States(){
//    for(int i = 0; i < states.size(); i++)
//    {
//        this->states[(State)i] = true;
//    }
//}
//bool States::isStateEnable(State state) const
//{
//    if(states.count(state) > 0)
//    {
//        return states.at(state);
//    }
//    else
//        return false;
//}
//void States::enableState(State s)
//{
//    states[s] = true;
//}
//void States::disableState(State s)
//{
//    states[s] = false;
//}