/**
 * Queue Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "linked_list.h"

class Queue {
 private:
  LinkedList list;

 public:
  void push(int item);
  void pop();
  int front();
  bool empty();
};

#endif  // QUEUE_H_