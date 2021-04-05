/**
 * Linked List - Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Node.h"
#include <cstddef>  // size_t

// Create the LinkedList
template <class L>
class LinkedList {
 private:
  Node<L>* head;
  Node<L>* tail;

 public:
  // Default constructor
  LinkedList();

  // Destructor
  ~LinkedList();

  // Assignment operator
  LinkedList<L>& operator=(const LinkedList<L>& l);

  // Copy constructor
  LinkedList(const LinkedList<L> &l);

  // Get the head
  Node<L>* accessHead();

  // Get the tail
  Node<L>* accessTail();

  // Create a new node
  Node<L>* createNode(L item);

  // Insert item to the tail of the list
  void insertTail(L item);

  // Insert item to the head of the list
  void insertHead(L item);

  // Remove the head of the list
  void removeHead();

  // Return the item store in the head
  L getHead();

  // Find the size of the list
  size_t getSize();

  // Check if the list is empty
  bool ifEmpty();

  // Find the item that is n from the list head (with the head a n = 0; the next
  // at n = 1, and so on)
  L find(int n);
};

#include "LinkedList.cpp"
#endif  // LINKEDLIST_H_