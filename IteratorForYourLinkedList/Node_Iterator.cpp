/**
 * Node Iterator Implementaion File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef NODE_ITERATOR_CPP_
#define NODE_ITERATOR_CPP_
#include "Node_Iterator.h"
#include "Tml_Dbl_LinkedList.h"
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
  current = current->linkNext;
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
  // std::cout << "pre-- starts" << std::endl;
  current = current->linkPrev;
  // std::cout << "pre-- ends" << std::endl;
  return *this;
}

template <class T>
Node_Iterator<T> Node_Iterator<T>::operator--(int) {
  // Create a temporary
  Node_Iterator<T>* temporary = *this;
  current = current->linkPrev;
  return current;
}

template <class T>
T& Node_Iterator<T>::operator*() const {
  return current->info;
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