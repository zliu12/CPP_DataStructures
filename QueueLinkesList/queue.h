/**
 * Queue - Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "LinkedList.h"
#include <cstddef>  // size_t

// Create the stack
template <class Q>
class Queue {
 private:
  LinkedList<Q> list;

 public:
  // Default constructor
  Queue();
  // Destructor
  ~Queue();
  // Assignment operator
  Queue<Q>& operator=(const Queue<Q> &q);
  // Copy constructor
  Queue(const Queue<Q>& q);
  // remove an item from th`e stack, first come first pop
  void pop();
  // add an item to the stack
  void push(Q item);
  // returns true if there are no items in the stack, otherwise false
  bool empty();
  // returns the number of items in the stack
  size_t size();
  // returns the item in the front of the queue, without removing it
  Q front();
  // returns the item that is n from the top (with the top a idx = 0, the next
  // at idx = 1, and so on)
  Q seek(int idx);
};

#include "queue.cpp"
#endif  // QUEUE_H_