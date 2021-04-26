
#ifndef States_hpp
#define States_hpp

#include <map>

class States{
public:
    enum ObjectState{
        HIDDEN, HIGHLIGHTED, DISABLED, BLINKON, LASTSTATE
    };
    States();
    void operator=(const States& other);
    static bool isStateEnabled(ObjectState state);
    static void setStateEnable(ObjectState state, bool set);
     
    
    
private:
    static std::map<ObjectState, bool> states;
    
    
    
};


#endif /* States_hpp */
