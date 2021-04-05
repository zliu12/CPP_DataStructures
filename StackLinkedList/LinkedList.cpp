/**
 * Linked List Implementation File
 * 
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef LINKEDLIST_CPP_
#define LINKEDLIST_CPP_
#include "LinkedList.h"
#include <iostream>
#include <cassert>

// Default constructor
template <class L>
LinkedList<L>::LinkedList() {
  head = nullptr;
  tail = nullptr;
  listSize = 0;
}

// Destructor
template <class L>
LinkedList<L>::~LinkedList() {
  // Keep removing head while head isn't equal to nullptr
  while (head != nullptr) {
    removeHead();
  }
}

// Assignment operator
template <class L>
LinkedList<L>& LinkedList<L>::operator=(const LinkedList<L>& l) {
  // If it's "self-assignment"
  if (this == &l) {
    return *this;
  }
  // Empty the LHS copied list
  this->~LinkedList();
  // Create a "walker" n starts from the head
  Node<L>* n = l.head;
  // n walks through the list until it gets to the nullptr
  while (n != nullptr) {
    insertTail(n->item);
    n = n->next;
  }
  return *this;
}

// Copy constructor
template <class L>
// Initialize a linked list
LinkedList<L>::LinkedList(const LinkedList<L>& l) : LinkedList() {
  // *this = l is also fine
  (*this).operator=(l);
}

// Get the head
template <class L>
Node<L>* LinkedList<L>::accessHead() const {
  return head;
}

// Get the tail
template <class L>
Node<L>* LinkedList<L>::accessTail() const {
  return tail;
}

// Create a new Node
template <class L>
Node<L>* LinkedList<L>::createNode(L item) {
  Node<L>* n = new Node<L>;
  n->item = item;
  n->next = nullptr;
  return n;
}

// Insert item to the head of the list
template <class L>
void LinkedList<L>::insertHead(L item) {
  // If the list is empty, insert a new Node
  if (head == nullptr) {
    // Create a new Node, set the head and tail to the new Node
    Node<L>* n = createNode(item);
    head = n;
    tail = n;
  } else {
    // Create a new Node
    Node<L>* n = createNode(item);
    // Point n's next to the original head
    n->next = head;
    // Set n the new head
    head = n;
  }
}

// Insert item to the tail of the list
template <class L>
void LinkedList<L>::insertTail(L item) {
  // If the list is empty, insert a new Node
  if (head == nullptr) {
    // Create a new Node, set the head and tail to the new Node
    Node<L>* n = createNode(item);
    head = n;
    tail = n;
  } else {
    // Create a new Node
    Node<L>* n = createNode(item);
    // Point tail's next to n
    tail->next = n;
    // Set n the new tail
    tail = n;
  }
}


// Remove the head of the list
template <class L>
void LinkedList<L>::removeHead() {
  // If the list is empty, return
  if (head == nullptr) {
    std::cout << "Empty list, nothing to remove" << std::endl;
    return;
  } else {
    Node<L>* n = head;
    head = head->next;
    delete n;
  }
}

// Return the item stored in the head
template <class L>
L LinkedList<L>::getHead() {
  if (head == nullptr) {
    std::cout << "Empty list, nothing to remove" << std::endl;
    return 0;
  }
  return head->item;
}

// Get the size of the list
template <class L>
size_t LinkedList<L>::getListSize() {
  // Initialize the listSize to 0
  listSize = 0;
  // Create a "walker" starts from the list head
  Node<L>* n = head;
  // n traverses through the list until gets to the nullptr
  while (n != nullptr) {
    n = n->next;
    listSize++;
  }
  return listSize;
}

// Find the item that is n from the list head (with the head a n = 0; the
// next at n = 1, and so do)
template <class L>
L LinkedList<L>::find(int idx) {
  // If n is greater than the list size
  assert(idx < getListSize());
  // Create an index stars from 0
  int index = 0;
  // Create a Node starts from the list head
  Node<L>* n = head;
  while (index != idx) {
    n = n->next;
    index++;
  }
  return n->item;
}

// Check if the list is empty
template <class L>
bool LinkedList<L>::ifEmpty() {
  return (head == nullptr);
}

#endif  // LINKEDLIST_CPP_