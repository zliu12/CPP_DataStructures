/**
 * Stack - Implementation File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef STACK_CPP_
#define STACK_CPP_
#include "stack.h"
#include <iostream>
#include <cassert>

// Default constructor
template <class S>
Stack<S>::Stack() {
  LinkedList<S> list;
}

// Destructor
template <class S>
Stack<S>::~Stack() {
  list.~LinkedList();
}

// Copy constructor
template <class S>
Stack<S>::Stack(const Stack<S>& s) : Stack() {
  *this = s;
}

// Assignment operator
template <class S>
Stack<S>& Stack<S>::operator=(const Stack<S>& s) {
  list = s.list;
  return *this;
}

// Remove an item from the stack
template <class S>
void Stack<S>::pop() {
  list.removeHead();
}

// Add an item to the stack
template <class S>
void Stack<S>::push(S item) {
  list.insertHead(item);
}

// returns true if there are no items in the stack, otherwise false
template <class S>
bool Stack<S>::empty() {
  return list.ifEmpty();
}

// returns the number of items in the stack
template <class S>
size_t Stack<S>::size() {
  return list.getListSize();
}

// returns the item on the top of the stack, without removing it
template <class S>
S Stack<S>::top() {
  return list.getHead();
}

// returns the item that is n from the top (with the top a idx = 0, the next
// at idx = 1, and so on)
template <class S>
S Stack<S>::seek(int idx) {
  return list.find(idx);
}

#endif  // STACK_CPP_