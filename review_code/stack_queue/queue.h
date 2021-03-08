/**
 * Queue Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include "../linked_list/linked_list.h"

class Queue {
 private:
  LinkedList list;

 public:
  // Returned type is void bcuz we just need to push item into the queue, affect
  // the opposite side of queue.pop()
  void push(int item);
  // Returned type is void bcuz we just need to remove item from the queue,
  // affect the opposite side of queue.push(); 
  void pop();
  // Return the first item being pushed at the moment
  int front();
  // Check if queue has any members
  bool empty();
};