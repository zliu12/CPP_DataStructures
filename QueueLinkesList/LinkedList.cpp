/**
 * Linked List - Implementation File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef LINKEDLIST_CPP_
#define LINKEDLIST_CPP_
#include "LinkedList.h"
#include <iostream>
#include <cassert>

template <class L>
LinkedList<L>::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

template <class L>
LinkedList<L>::~LinkedList() {
  while (head != nullptr) {
    removeHead();
  }
}

template <class L>
LinkedList<L>& LinkedList<L>::operator=(const LinkedList<L>& l) {
  // if it is "self-assignment"
  if (this == &l) {
    return *this;
  }
  // clear up the copied list be4 copying elements into it
  this->~LinkedList();
  // create a "walker" starts from list head
  Node<L>* n = l.head;
  while (n != nullptr) {
    insertTail(n->item);
    n = n->next;
  }
  return *this;
}

template <class L>
LinkedList<L>::LinkedList(const LinkedList<L> &l) : LinkedList() {
  // Make a new(copied) list by copying from l
  *this = l;
}

template <class L>
Node<L>* LinkedList<L>::accessHead() {
  return head;
}

template <class L>
Node<L>* LinkedList<L>::accessTail() {
  return tail;
}

template <class L>
Node<L>* LinkedList<L>::createNode(L item) {
  Node<L>* n = new Node<L>;
  n->item = item;
  n->next = nullptr;
  return n;
}

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
    // Point n's next to head
    n->next = head;
    // Set n the new head
    head = n;
  }
}

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
    // Set n as the new tail
    tail = n;
  }
}

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

template <class L>
L LinkedList<L>::getHead() {
  if (head == nullptr) {
    std::cout << "Empty list, nothing to remove" << std::endl;
    return 0;
  }
  return head->item;
}

template <class L>
size_t LinkedList<L>::getSize() {
  // Create a counter, starts from 0, increments 1 every time n "jumps",
  // counts the times that n "jumps", 
  size_t counter = 0;
  // If the list is empty, return
  if (head == nullptr) {
    std::cout << "Nothing in the list";
    return 0;
  } else {
    // Create a "walker", starts from head
    Node<L>* n = head;
    // n traverses through the list until the nullptr
    while (n != nullptr) {
      n = n->next;
      counter++;
    }
  }
  return counter;
}

template <class L>
bool LinkedList<L>::ifEmpty() {
  return (head == nullptr);
}

template <class L>
L LinkedList<L>::find(int n) {
  // If n is greater than the list size
  assert(n < getSize());
  // Create a Node starts from the list head
  Node<L>* m = head;
  // Create a idx starts from the 0
  int idx = 0;
  while (idx != n) {
    m = m->next;
    idx++;
  } 
  return m->item;
}



#endif  // LINKEDLIST_CPP_