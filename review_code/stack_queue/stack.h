/**
 * Stack Header File - First In Last Out
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* Real Life Example of Stack
Pancakes, CDs, Textbooks, cash, cash, legos
Rule of Using Computer Stack:Last in first out (LIFO) / First in last out (FILO)
 */

/* Real Life Example of Queue
DMV lines, class waitlist, playlist
Rule of Using Computer Queue: First in first out(FIFO) */

/* class Queue 
function push: add item to the queue
function pop: take out the next item in the queue
function front: get the value at the front of the queue
function empty: return true if queue is empty, otherwise false
Queue push and pop on the oppsite side
Stack push and pop on the same side */

#ifndef STACK_H_
#define STACK_H_

#include "../linked_list/linked_list.h"

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