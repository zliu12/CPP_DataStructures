/**
 * Queue - Implementation File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef QUEUE_CPP_
#define QUEUE_CPP_
#include "queue.h"
#include <iostream>
#include <cassert>

template <class Q>
Queue<Q>::Queue() {
  LinkedList<Q> list;
}
 
template <class Q>
Queue<Q>::~Queue() {
  list.~LinkedList();
}

template <class Q>
Queue<Q>& Queue<Q>::operator=(const Queue<Q> &q) {
  list = q.list;
  return *this;
}

template <class Q>
Queue<Q>::Queue(const Queue<Q>& q) : Queue() {
  *this = q;
}

template <class Q>
void Queue<Q>::pop() {
  list.removeHead();
}

template <class Q>
void Queue<Q>::push(Q item) {
  list.insertTail(item);
}

template <class Q>
bool Queue<Q>::empty() {
  return list.ifEmpty();
}

template <class Q>
size_t Queue<Q>::size() {
  return list.getSize();
}

template <class Q>
Q Queue<Q>::front() {
  return list.getHead();
}

template <class Q>
Q Queue<Q>::seek(int idx) {
  return list.find(idx);
}

#endif  // QUEUE_CPP_