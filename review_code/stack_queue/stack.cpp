/**
 * Stack Implementation - First In Last Out
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include "Stack.h"

void Stack::push(int item) {
  list.insertHead(item);  
}

void Stack::pop() {
  list.removeHead();
}

int Stack::top() {
  return list.getHead();
}

bool Stack::empty() {
  return list.getHead() == 0;
}

