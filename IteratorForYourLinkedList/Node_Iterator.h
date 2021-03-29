/**
 * Node_Iterator Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef NODE_ITERATOR_H_
#define NODE_ITERATOR_H_
#include "Node.h"
#include <iterator>

template <class T>
class Node_Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
 private:
  Node<T>* current;
 
 public:
  // Default constructor
  Node_Iterator();
  // Constructor
  Node_Iterator(Node<T>* nodeAssignToCurrent);
  // Overload prefix++
  Node_Iterator<T>& operator++();
  // Overload postfix++
  Node_Iterator<T> operator++(int);
  // Overload prefix--
  Node_Iterator<T>& operator--();
  // Overload postfix--
  Node_Iterator<T> operator--(int);
  // Overload dereference operator
  T& operator*() const;

  template <class S>
  // Overload compare equal operator
  friend bool operator==(const Node_Iterator<S>& LHS, const Node_Iterator<S>& RHS);
  // Overload compare not equal operator
  template <class S>
  friend bool operator!=(const Node_Iterator<S>& LHS, const Node_Iterator<S>& RHS);
};

#include "Node_Iterator.cpp"
#endif  // NODE_ITERATOR_H_
