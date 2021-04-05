/**
 * Stack - Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef STACK_H_
#define STACK_H_
#include "LinkedList.h"       // Linked List class
#include <cstddef>            // size_t

// Create the stack
template <class S>
class Stack {
 private:
  LinkedList<S> list;

 public:
  // Default constructor
  Stack();

  // Destructor
  ~Stack();

  // Copy constructor
  Stack(const Stack<S>& s);
  
  // Assignment operator
  Stack<S> &operator=(const Stack<S>& s);
  
  // remove an item from the stack
  void pop();

  // add an item to the stack
  void push(S item);

  
  // returns true if there are no items in the stack, otherwise false
  bool empty();

  // returns the number of items in the stack
  size_t size();

  // returns the item on the top of the stack, without removing it
  S top();

  // returns the item that is n from the top (with the top a idx = 0, the next
  // at idx = 1, and so on)
  S seek(int idx);
};

#include "stack.cpp"
#endif  // STACK_H_