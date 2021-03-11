/**
 * Queue Implementation - First In First Out
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include "Queue.h"

void Queue::push(int item) {
  // Bcuz insert to the tail, we'll push from the head
  list.insertTail(item);  
}

void Queue::pop() {
  // Remove from head indicates we push to tail
  list.removeHead();
}

int Queue::front() {
  return list.getHead();
}

bool Queue::empty() {
  return list.getHead() == 0;
}
