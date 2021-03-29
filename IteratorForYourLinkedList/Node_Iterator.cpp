/**
 * Node Iterator Implementaion File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef NODE_ITERATOR_CPP_
#define NODE_ITERATOR_CPP_
#include "Node_Iterator.h"
#include "linked_list.h"
#include <iostream>

template <class T>
Node_Iterator<T>::Node_Iterator() {
  current = nullptr;
}

template <class T>
Node_Iterator<T>::Node_Iterator(Node<T>* nodeAssignToCurrent) {
  current = nodeAssignToCurrent;
}

template <class T>
Node_Iterator<T>& Node_Iterator<T>::operator++() {
  current = current->next;
  return *this;
}

template <class T>
Node_Iterator<T> Node_Iterator<T>::operator++(int) {
  // Create a temporary
  Node_Iterator<T>* temporary = *this;
  current = current->next;
  return temporary;
}

template <class T>
Node_Iterator<T>& Node_Iterator<T>::operator--() {
  // If nothing is in the front (current is head)
  Node<T>* nPrev = previousNode(current);
  if (nPrev == nullptr) {
    std::cout << "Nothing in the front." << std::endl;
  }
  else {
    // Current points to the Node in front of it
    current = previousNode(current);
  }
  return *this;
}

template <class T>
Node_Iterator<T> Node_Iterator<T>::operator--(int) {
  Node_Iterator<T>* temporary = *this;
  // If nothing is in the front (current is head)
  if (previousNode(current) == nullptr) {
    std::cout << "Nothing in the front." << std::endl;
  }
  else {
    // Current points to the Node in front of it
    current = previousNode(current);
  }
  return current;
}

template <class T>
T& Node_Iterator<T>::operator*() const {
  return current->data;
}

template <class S>
bool operator==(const Node_Iterator<S>& LHS, const Node_Iterator<S>& RHS) {
  return LHS.current == RHS.current;
}

template <class S>
bool operator!=(const Node_Iterator<S>& LHS, const Node_Iterator<S>& RHS) {
  return LHS.current != RHS.current;
}

#endif  // NODE_ITERATOR_CPP_