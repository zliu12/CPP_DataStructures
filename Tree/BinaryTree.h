/**
 * BinaryTree - Hearder
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>
#include "Node.h"

namespace {
  template <class T>
  void output(T& data) {
    std::cout << data << "\t";
  }
}

template <class T>
class BinaryTree {
 private:
  Node<T>* root;
  // void f(T&) = output is the function parameter with the output function as
  // the default value, so f(T&) will be output(T& data) unless specified
  void inOrder(Node<T>* root, void f(T&) = output);
  void postOrder(Node<T>* root, void f(T&) = output);
  void preOrder(Node<T>* root, void f(T&) = output);
  void push(T data, Node<T>*& root);

 public:
  void push(T data);
  void operator+=(T data);
  void inOrder(void f(T&) = output);
  void postOrder(void f(T&) = output);
  void preOrder(void f(T&) = output);
};

#include "BinaryTree.cpp"
#endif  // BINARYTREE_H_