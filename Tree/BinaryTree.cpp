/**
 * BinaryTree - Implementation
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef BINARYTREE_CPP_
#define BINARYTREE_CPP_
#include "BinaryTree.h"

template <class T>
void BinaryTree<T>::inOrder(Node<T>* root, void f(T&)) {
  // Base case
  if(root == nullptr) {
    return;
  }
  inOrder(root->left, f);
  f(root->data);
  inOrder(root->right, f);
}

template <class T>
void BinaryTree<T>::postOrder(Node<T>* root, void f(T&)) {
  // Base case
  if(root == nullptr) {
    return;
  }
  postOrder(root->left, f);
  postOrder(root->right, f);
  f(root->data);
}

template <class T>
void BinaryTree<T>::preOrder(Node<T>* root, void f(T&)) {
  // Base case
  if(root == nullptr) {
    return;
  }
  f(root->data);
  preOrder(root->left, f);
  preOrder(root->right, f);
}

template <class T>
void BinaryTree<T>::push(T data, Node<T>*& root) {
  if(root == nullptr) {
    root = new Node<T>;
    root->data = data;
    root->left = nullptr;
    root->right = nullptr;
    return;
  }

  if(data <= root->data) {
    push(data, root->left);
  }
  else {
    push(data, root->right);
  }
}

template <class T>
void BinaryTree<T>::push(T data) {
  push(data, root);
}

template <class T>
void BinaryTree<T>::operator+=(T data) {
  push(data, root);
}


template <class T>
void BinaryTree<T>::inOrder(void f(T&)) {
  inOrder(root, f);
}

template <class T>
void BinaryTree<T>::postOrder(void f(T&)) {
  postOrder(root, f);
}

template <class T>
void BinaryTree<T>::preOrder(void f(T&)) {
  preOrder(root, f);
}

#endif  // BINARYTREE_CPP_