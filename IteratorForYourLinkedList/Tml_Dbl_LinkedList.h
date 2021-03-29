/**
 * Template Doubly Linked List - Header
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef TML_DBL_LINKEDLIST_H_
#define TML_DBL_LINKEDLIST_H_
#include "Node.h"
#include "Node_Iterator.h"
#include <cstdlib>
#include <iostream>



template <class T>
class DlinkedList {
private:
  T count = 0;
  Node<T> *head;
  Node<T> *tail;
  Node<T> *createNode(T value);                 // Create a node
  Node<T> *findNode(T value);                   // Find if a node is in the list
  Node<T> *previousNode(Node<T> *targetNode);   // The node before a particular node
  Node<T> *subsequentNode(Node<T> *targetNode); // The node after a particular node
  void insertIfEmpty(T value);                  // Insert a node if the list is empty
  void removeNode(Node<T> *targetNode);         // Remove a particular node

public:
  DlinkedList();                                // Default constructor
  ~DlinkedList();                               // Big3: destructor
  DlinkedList &operator=(const DlinkedList &l); // Big3: assignment operator
  DlinkedList(const DlinkedList &l);            // Big3: copy constructor
  void insertAtBegin(T value);                  // Insert at list beginning
  void insertAtEnd(T value);                    // Insert at list end
  void operator+=(T value);                     // Overload the += operator
  void remove(T removeValue);                   // Remove an item
  T getSize();                                  // Check the size of the list
  void removeALL();                             // Clear the list
  bool listEmpty();                             // Check if the list is empty
  bool findValue(T targetValue);                // Find a value
  // Insert before a particular node
  void insertBeforeNode(T insertValue, T targetValue);
  // Insert after a particular node
  void insertAfterNode(T insertValue, T targetValue);

  template <class P>
  // Print all the nodes' info in the list
  friend std::ostream &operator<<(std::ostream &out, const DlinkedList<P> &l);

  // This is for the Node_Iterator
  Node_Iterator<T> begin();
  // This is for the Node_Iterator
  Node_Iterator<T> end();
};

#include "Tml_Dbl_LinkedList.cpp"
#endif // TML_DBL_LINKEDLIST_H_