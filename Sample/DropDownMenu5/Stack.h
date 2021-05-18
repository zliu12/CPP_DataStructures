//
// Created by xu200 on 4/11/2021.
//

#ifndef PROJECT1_STACK_H
#define PROJECT1_STACK_H
#include "LinkedList.h"
template<class T>
class Stack : public LinkedList<T> {
public:
    void pop(); // removes an itembox from the stack
    void push(T item); // adds an itembox to the stack
    T top();
    T seek(int n);


};

#include "Stack.cpp"

#endif //PROJECT1_STACK_H
