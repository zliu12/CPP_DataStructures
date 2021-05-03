/**
 * Node - Header
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef NODE_H_
#define NODE_H_

template <class T>
class Node {
  public:
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
};

#endif   // NODE_H_