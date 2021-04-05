/**
 * Node Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */
// Create the Node
#ifndef NODE_H_
#define NODE_H_

template <class T>
class Node {
 public:
  T item;
  Node<T>* next;
};

#endif  // NODE_H_