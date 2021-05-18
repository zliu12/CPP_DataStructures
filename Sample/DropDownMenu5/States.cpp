
#include "States.h"
States::States(){
    for (int i=0; i<LASTSTATE; i++)
    {
        states[static_cast<ObjectState>(i)]= false;
    }

}

bool States::checkState(ObjectState state) const
{
    if(states.count(state)>0)
    {
        return states.at(state);
    }
    return false;
}
void States::enableState(ObjectState state)
{
    states[state]= true;
}
void States::disableState(ObjectState state)
{
    states[state]= false;

}
