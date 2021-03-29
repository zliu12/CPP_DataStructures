/**
 * Linked List Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "node.h"
#include "Node_Iterator.h"
#include <iostream>

template <class T>
class LinkedList {
 private:
  Node<T>* head;
  Node<T>* tail;
  // Create a new node
  Node<T>* createNode(T item); 

  // Find the node with the number item in it
  Node<T>* find(T item);
  Node<T>* previousNode(Node<T>* node_target);

  // Only call this when find head and tail are NULL
  void insertFirst(T item);

  /* Overload the remove function so that we can remove that particular node
  that we find, so it has node as the parameter */
  void remove(Node<T>* node_target);

 public:
  // Default constructor
  LinkedList();
  // A destructor has the same name as the class, with a tilde in the front
  ~LinkedList();                                        // Big3: Destructor                              
  LinkedList(const LinkedList<T>& list);                // Big3: Copy constructor
  LinkedList<T>& operator=(const LinkedList<T>& list);  // Big3: Assignment operator
  void insertHead(T item);
  void insertTail(T item);

  /* Call find to find the node with the value in it, then pass that node to the
  remove(Node *node) function and the remove function will do the removing 
  process */
  void remove(T item);
  void removeHead();
  T getHead();

  // This is for the Node_Iterator
  Node_Iterator<T> begin();
  // This is for the Node_Iterator
  Node_Iterator<T> end();

  template <class S>
  friend std::ostream &operator<<(std::ostream &out, const LinkedList<S>& list);
};

#include "linked_list.cpp"
#endif    // LINKED_LIST_H_