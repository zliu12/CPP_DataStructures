/**
 * Template Doubly Linked List - Implementation
 *
 * Copyright (c) [2021], Zhao Liu.
 */
#ifndef TML_DBL_LINKEDLIST_CPP_
#define TML_DBL_LINKEDLIST_CPP_

#include "Tml_Dbl_LinkedList.h"
#include <iostream>

template <class T>
// Create a node
Node<T> *DlinkedList<T>::createNode(T value) {
  // Create a new node n
  Node<T> *n = new Node<T>;
  // Set n's infor to value, n's linkNext & linkPrev to nullptr
  n->info = value;
  n->linkNext = nullptr;
  n->linkPrev = nullptr;
  return n;
}

template <class T>
// Find if a node is in the list
Node<T> *DlinkedList<T>::findNode(T value) {
  // Create a cursor, point it to head
  Node<T> *cursor = head;
  // cursor traverses the list until finds the value or reaches a NULL
  while (cursor != nullptr && cursor->info != value) {
    cursor = cursor->linkNext;
  }
  return cursor;
}

template <class T>
// The node before a particular node
Node<T> *DlinkedList<T>::previousNode(Node<T> *targetNode) {
  // Create a cursor, point it to head
  Node<T> *cursor = head;
  // cursor traverses the list until reaches a NULL or finds the target node
  while (cursor != nullptr && cursor->linkNext != targetNode) {
    cursor = cursor->linkNext;
  }
  return cursor;
}

template <class T>
// The node after a particular node
Node<T> *DlinkedList<T>::subsequentNode(Node<T> *targetNode) {
  // // Create a cursor, point it to tail
  // Node *cursor = tail;
  // // cursor traverses the list until reaches a NULL or finds the target node
  // while (cursor != nullptr && cursor->linkPrev != targetNode)
  // {
  //   cursor = cursor->linkPrev;
  // }
  // return cursor;
  Node<T> *cursor = head;
  while (cursor != nullptr && cursor != targetNode->linkNext) {
    cursor = cursor->linkNext;
  }
  return cursor;
}

template <class T>
// Insert a node if the list is empty
void DlinkedList<T>::insertIfEmpty(T value) {
  // Create a new Node n
  Node<T> *n = createNode(value);
  // Point head and tail to n
  head = n;
  tail = n;
}

template <class T>
// Remove a particular node
void DlinkedList<T>::removeNode(Node<T> *targetNode) {
  // std::cout << "removeNode starts" << std::endl;
  // If the targetNode is a NULL
  if (targetNode == nullptr) {
    std::cout << "target node is a NULL" << std::endl;
    return;
  } 
  else {
    // If the list is empty
    if (listEmpty()) {
      // std::cout << "Line 73: list is empty" << std::endl;
      return;
    }
    // If the list has only 1 node
    else if (head == tail) {
      // Point head and tail to the NULL
      head = nullptr;
      tail = nullptr;
      // Delete the targetNode
      delete targetNode;
    }
    // If the targetNode is the head
    else if (targetNode == head) {
      // std::cout << "targetNode == head starts" << std::endl;
      // Find the subsqNode that's subsequent to the head
      Node<T> *subsqNode = subsequentNode(targetNode);
      // std::cout << "subsqNode created" << std::endl;
      // The subsqNode links forward to the NULL
      subsqNode->linkPrev = nullptr;
      // std::cout << "subsqNode->linkPrev = nullptr ends" << std::endl;
      // The head links backward to the NULL
      head->linkNext = nullptr;
      // Set the subsqNode the new head
      head = subsqNode;
      // Delete the targetNode
      delete targetNode;
    }
    // If the targetNode is the tail
    else if (targetNode == tail) {
      // Find the prevNode that's previous to the targetNode
      Node<T> *prevNode = previousNode(targetNode);
      // The prevNode links backward to the NULL
      prevNode->linkNext = nullptr;
      // The tail links forward to the NULL
      tail->linkPrev = nullptr;
      // Set the prevNode the new tail
      tail = prevNode;
      // Delete the targeNode
      delete targetNode;
    }
    // If the targetNode is in between head and tail
    else {
      // Find the prevNode that's previous to the targetNode
      Node<T> *prevNode = previousNode(targetNode);
      // Find the subsqNode that's subsequent to the targetNode
      Node<T> *subsqNode = subsequentNode(targetNode);
      // The prevNode links backward to the subsqNode
      prevNode->linkNext = subsqNode;
      // The subsqNode links forward to the prevNode
      subsqNode->linkPrev = prevNode;
      // Delete the targetNode
      delete targetNode;
    }
  }
  // std::cout << "removeNode ends" << std::endl;
}

template <class T>
// Default constructor
DlinkedList<T>::DlinkedList() {
  head = nullptr;
  tail = nullptr;
  // std::cout << "constructor ends" << std::endl;
}

template <class T>
// Destructor
DlinkedList<T>::~DlinkedList() {
  // std::cout << "destructor starts" << std::endl;
  while (head != nullptr) {
    removeNode(head);
  }
  // std::cout << "destructor ends" << std::endl;
}

template <class T>
// Assignment opeartor
DlinkedList<T> &DlinkedList<T>::operator=(const DlinkedList<T> &l) {
  // If it is "self-assignment"
  if (this == &l) {
    return *this;
  }
  // Clear up the copied list be4 copying nodes to it
  this->~DlinkedList();
  Node<T> *cursor = l.head;
  while (cursor != nullptr) {
    insertAtEnd(cursor->info);
    cursor = cursor->linkNext;
  }
  // std::cout << "assignment operator ends" << std::endl;
  return *this;
}

template <class T>
// Copy constructor
DlinkedList<T>::DlinkedList(const DlinkedList<T> &l) : DlinkedList() {
  // Make me a new(copied) list by copying from l
  *this = l;
  // std::cout << "copy constructor ends" << std::endl;
}

template <class T>
// Insert at list beginning
void DlinkedList<T>::insertAtBegin(T value) {
  // If the list is empty, create a node and insert to list
  if (listEmpty()) {
    insertIfEmpty(value);
  } else {
    // Create a new Node n
    Node<T> *n = createNode(value);
    // Point n's linkNext to head
    n->linkNext = head;
    // Set n the new head
    head = n;
  }
  // std::cout << "insertAtBegin ends" << std::endl;
}

template <class T>
// Insert at list end
void DlinkedList<T>::insertAtEnd(T value) {
  // If the list is empty, create a node and insert to list
  if (listEmpty()) {
    insertIfEmpty(value);
  } else {
    // Create a new Node n
    Node<T> *n = createNode(value);
    // Point n's linkPrev to tail
    n->linkPrev = tail;
    // Point tail's linkNext to n
    tail->linkNext = n;
    // Set n the new tail
    tail = n;
  }
  // std::cout << "insertAtEnd ends" << std::endl;
}

template <class T>
// Overload the += operator
void DlinkedList<T>::operator+=(T value) {
  insertAtEnd(value);
}

template <class T>
// Insert before a particular node
void DlinkedList<T>::insertBeforeNode(T insertValue, T targetvalue) {
  // Check if the target value exists
  if (findNode(targetvalue) == nullptr) {
    std::cout << "No node has the value as " << targetvalue << std::endl;
    return;
  } else if (findNode(targetvalue) == head) {
    insertAtBegin(targetvalue);
  } else {
    // Find the targetNode that has the targetValue
    Node<T> *targetNode = findNode(targetvalue);
    // Find the prevNode that's previous to the targetNode
    Node<T> *prevNode = previousNode(targetNode);
    // Create the insertNode that has the value needed to insert
    Node<T> *insertNode = createNode(insertValue);
    // The prevNode links backward to the insertNode
    prevNode->linkNext = insertNode;
    // The insertNode links forward to the prevNode
    insertNode->linkPrev = prevNode;
    // The insertNode links backward to the targetNode
    insertNode->linkNext = targetNode;
    // The targetNode links forward to the insertNode
    targetNode->linkPrev = insertNode;
  }
}

template <class T>
// Insert after a particular node
void DlinkedList<T>::insertAfterNode(T insertValue, T targetvalue) {
  // Check if the target value exists
  if (findNode(targetvalue) == nullptr) {
    std::cout << "No node has the value as " << targetvalue << std::endl;
    return;
  } else if (findNode(targetvalue) == tail) {
    insertAtEnd(insertValue);
  } else {
    // Find the targetNode that has the targetvalue
    Node<T> *targetNode = findNode(targetvalue);
    // Find the subsqNode that's subsequent to the targetNode
    Node<T> *subsqNode = subsequentNode(targetNode);
    // Create the insertNode that has the value needed for insert
    Node<T> *insertNode = createNode(insertValue);
    // The subsqNode links forward to the insertNode
    subsqNode->linkPrev = insertNode;
    // The insertNode links backward to the subsqNode
    insertNode->linkNext = subsqNode;
    // The insertNode links forward to the targetNode
    insertNode->linkPrev = targetNode;
    // The targetNode links backward to the insertNode
    targetNode->linkNext = insertNode;
  }
}

template <class T>
// Remove an item
void DlinkedList<T>::remove(T removeValue) {
  // Find the targetNode that has the removeValue
  Node<T> *targetNode = findNode(removeValue);
  // Remove the targetNode
  removeNode(targetNode);
}

template <class T>
// Check the size of the list
T DlinkedList<T>::getSize() {
  // Create a cursor, point it to head
  Node<T> *cursor = head;
  // count now is 1 since cursor is at head
  count = 0;
  // cursor traverses the list until reaches a NULL, count increases by 1 each
  // time cursor moves to the next node
  while (cursor != nullptr) {
    cursor = cursor->linkNext;
    count++;
  }
  return count;
}

template <class T>
// Clear the list
void DlinkedList<T>::removeALL() {
  // If the list is empty already
  if (listEmpty()) {
    std::cout << "list is empty, nothing to remove" << std::endl;
  } else {
    // ALA the list is not empty
    while (!listEmpty()) {
      // Remove the head of the current list
      removeNode(head);
    }
  }
}

template <class T>
// Check if the list is empty
bool DlinkedList<T>::listEmpty() {
  // Empty if the head points to a NULL
  if (head == nullptr) {
    return true;
  }
  return false;
}

template <class T>
// Fine a value
bool DlinkedList<T>::findValue(T targetValue) {
  if (findNode(targetValue) == nullptr) {
    return false;
  }
  return true;
}

template <class P>
// Print all the nodes' info in the list
std::ostream &operator<<(std::ostream &out, const DlinkedList<P> &l) {
  for (Node<P> *cursor = l.head; cursor != nullptr; cursor = cursor->linkNext) {
    out << cursor->info << " ";
  }
  // std::cout << "<< ends" << std::endl;
  return out;
}

template <class T>
Node_Iterator<T> DlinkedList<T>::begin() {
  // std::cout << "begin() ends" << std::endl;
  return Node_Iterator<T>(head);
}

template <class T>
Node_Iterator<T> DlinkedList<T>::end() {
  // std::cout << "end() ends" << std::endl;
  return Node_Iterator<T>(nullptr);
}

template <class T>
Node_Iterator<T> DlinkedList<T>::getTail() {
  return tail;
}

#endif // TML_DBL_LINKEDLIST_CPP_