/**
 * Node Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */
#ifndef NODE_H_
#define NODE_H_

template <class T>
class Node {
public:
  T info;
  Node<T>* linkNext = nullptr;
  Node<T>* linkPrev = nullptr;
};

#include "Node.cpp"
#endif  // NODE_H_