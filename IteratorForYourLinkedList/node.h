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
  T data;
  Node<T>* next = nullptr;
};

#include "node.cpp"
#endif    // NODE_H_