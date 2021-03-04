/**
 * Stack Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */


#ifndef STACK_H_
#define STACK_H_
#include "linked_list.h"

class Stack {
 private:
  LinkedList list;

 public:
  void push(int item);
  void pop();
  int top();
  bool empty();
};

#endif  // STACK_H_