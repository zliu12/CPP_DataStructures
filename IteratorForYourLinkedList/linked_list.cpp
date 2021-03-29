/**
 * Linked List Implementation File.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef LINKED_LIST_CPP_
#define LINKED_LIST_CPP_
#include "linked_list.h"
#include <iostream>

template <class T>
Node<T>* LinkedList<T>::createNode(T item) {
  // A new node is created somewhere on the memory, when get out the function
  // scope, the ptr (local var n) gets deleted, but the memory allcoated for
  // the new node gets remained on the memory although the ptr is deleted
  Node<T>* n = new Node<T>;
  n->data = item;
  n->next = nullptr;
  return n;
}

template <class T>
Node<T>* LinkedList<T>::find(T item) {
  // Create a walker pts the same memory address as the head
  Node<T>* walker = head;
  while (walker != tail->next && walker->data != item) {
    walker = walker->next;
  }
  return walker;
}

template <class T>
Node<T>* LinkedList<T>::previousNode(Node<T>* node_target) {
  Node<T>* walker = head;
  while (walker != nullptr && walker->next != node_target) {
    walker = walker->next;
  }
  return walker;
}

template <class T>
void LinkedList<T>::insertFirst(T item) {
  Node<T>* n = new Node<T>;
  n->data = item;
  tail = n;
  head = n;
}

template <class T>
void LinkedList<T>::remove(Node<T>* node_target) {
  // Check if the node_target is nullptr
  if (node_target == nullptr) {
    return;
  } else {
    // Check if list is empty
    if (head == nullptr) {
      return;
    } 
    // Check if list only has 1 member
    else if (head == tail) {
      head = nullptr;
      tail = nullptr;
      // delete node_target;
    }
    // Check if node_target is the head
    else if (node_target == head) {
      head = head->next;
      delete node_target;
    }
    // Check if node_target is the tail
    else if (node_target == tail) {
      tail = previousNode(node_target);
      tail->next = nullptr;
      delete node_target;
    }
    // If node_tarfet is in the middle
    else {
      Node<T>* prevNode = previousNode(node_target);
      prevNode->next = node_target->next;
      delete node_target;
    }
  }
}

template <class T>
LinkedList<T>::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
  // std::cout << "Destructor starts" << std::endl;
  while (head != nullptr) {
    // std::cout << *this << std::endl;
    remove(head);
  }
  // std::cout << "~LinkedList() ends" << std::endl;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) : LinkedList() {
  /* Call the assignment operator and perform its algorithm 
  same with: (*this).operator = (list), calling the member func of the obj and
  and passing list as a variable
   */
  // std::cout << "Copy constructor starts" << std::endl;
  // Here I tell the compiler: make me a new obj by copying from list
  *this = list;   // (*this).operator=(list);
  // std::cout << "Copy constructor ends" << std::endl;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list) {
  // std::cout << "Assignment operator starts" << std::endl;;
  /* Check if the list and this are the same place in the memory, if so, return
  this. If they are the same thing and then if we call the destructor(line 182),
  we would delete the list on the RHS and we wouldn't go further 
   */
  if (this == &list) {
    return *this;
  }
  /* If the list already has sth in it, I need to delete(deallocate that memory)
  be4 adding the stuff. Or, two things can happen depends on how we implement:
  1. have a linked list that's a union of the two linked lists
  2. have a memory leak
  So we have to get rid of what's on the LHS of the assignment operator be4 we
  assign the RHS
   */
  this->~LinkedList();
  Node<T>* walker = list.head;
  while (walker != nullptr) {
    insertTail(walker->data);
    walker = walker->next;
  }
  // std::cout << "Assignment operator ends" << std::endl;
  return *this;
}

template <class T>
void LinkedList<T>::insertHead(T item) {
  if (head == nullptr) {
    insertFirst(item);
  } else {
    Node<T>* n = createNode(item);
    n->next = head;
    head = n;
  }
}

template <class T>
void LinkedList<T>::insertTail(T item) {
  // If the header ptr points to null, it means nothing is in the list, so we
  // just simply insert the item and make the item the one and only element in
  // the list
  if (head == nullptr) {
    insertFirst(item);
  } else {
    // Create a new node
    Node<T>* n = createNode(item);
    // Tail still pting to the last node of the list rn, so tail->next denotes
    // the ptr var of the last node, by making it point to n, we're pting the 
    // last node to n, so the original last node becomes the second node to last
    // and n now becomes the last node
    tail->next = n;
    // Pting tail to n since n's been the last node
    tail = n;
  }
}

template <class T>
void LinkedList<T>::remove(T item) {
  remove(find(item));
}

template <class T>
void LinkedList<T>::removeHead() {
  remove(head);
}

template <class T>
T LinkedList<T>::getHead() {
  if (head != nullptr) {
    return head->data;
  }
  return 0;
}

template <class T>
Node_Iterator<T> LinkedList<T>::begin() {
  return Node_Iterator<T>(head);
}

template <class T>
Node_Iterator<T> LinkedList<T>::end() {
  return Node_Iterator<T>(nullptr);
}

template <class S>
std::ostream &operator<<(std::ostream &out, const LinkedList<S>& list) {
  Node<S> *walker = list.head;
  while (walker != nullptr) {
    out << walker->data;
    walker = walker->next;
  }
  return out;
}

#endif  // LINKED_LIST_CPP_