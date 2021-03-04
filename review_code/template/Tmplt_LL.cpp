/**
 * Template - LinkedList Implementation File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include "Tmplt_LL.h"

template <class T>
void LinkedList<T>::insertFirst(T item) {
  Node<T> *n = new Node;
  n->data = item;
  _tail = n;
  _head = n;
}

template <class T>
Node<T>* LinkedList<T>::createNode(T item) {
  Node<T> *n = new Node;
  n->data = item;
  n->next = nullptr;
  return n;
}

template <class T>
Node<T>* LinkedList<T>::find(T item) {
  Node<T> *walker = _head;
  while (walker->data != item && walker != _tail->next) {
    walker = walker->next;
  }
  return walker;
}

template <class T>
void LinkedList<T>::remove(Node<T> *node_remove) {
  // node_prior = walker, prevNode let walkr stops at the node prior to the
  // target(remove) node
  Node<T> *node_prior = prevNode(node_remove);
  // Return if the target is a null ptr
  if (node_remove == nullptr) {
    return;
  }
  // Head pts to NULL, return if the list is empty
  else if (_head == nullptr) {
    return;
  }
  // Head & tail pt to the same address, only 1 element in the list
  else if (_head == _tail) {
    _head = nullptr;    // Mk head pt NULL
    _tail = nullptr;    // Mk tail pt NULL
    delete node_prior;  // Release the free allocated to node_prior
  }
  // If the target is at the end (target is tail)
  else if (node_remove == _tail) {
    _tail = node_prior;     // Mk node_prior the new tail
    _tail->next = nullptr;  // Mk the ptr var of tail pt NULL
    delete node_remove;     // Delete target 
  }
  // If the target is at the beginning (target is head)
  else if (node_remove == _head) {
    _head = _head->next;    // Mk head pt to new head (2nd node)
    delete node_remove;     // delete target
  }
  // If the target is neither the above case, in the middle
  else {
    node_prior->next = node_remove->next; // node_priot pt to node after target
    delete node_remove;                   // delete target 
  }   
}

template <class T>
Node<T>* LinkedList<T>::prevNode(Node<T> *node_remove) {
  Node<T> *walker = _head;
  while (walker != nullptr && walker->next != node_remove) {
    walker = walker->next;
  }
  return walker;
}

template <class T>
void LinkedList<T>::insertHead(T item) {
  // If list empty, insert directly
  if (_head == nullptr) {
    insertFirst(item);
  }
  else {
    Node<T> *n = new Node;  // Create a new node n
    n->data = item;         // Mk val var of n equal to item
    n->next = _head;        // Mk ptr var of n pt to head
    _head = n;              // Mk n the new head
  }
}

template <class T>
void LinkedList<T>::insertTail(T item) {
  // If list empty, insert directly
  if (_head == nullptr) {
    insertFirst(item);
  }
  else {
    Node<T> *n = new Node;  // Create a new node n
    n->data = item;         // Mk val var of n equal to item
    n->next = nullptr;      // Mk ptr var of n pt NULL
    _tail->next = n;        // Mk original tail pt to n
    _tail = n;              // Mk n the new tail
  }
}

template <class T>
void LinkedList<T>::remove(T item){
  remove(find(item));
}

template <class T>
void LinkedList<T>::removeHead() {
  remove(_head);
}

template <class T>
T LinkedList<T>::get_head() {
  if (_head != nullptr) {
    return _head->data;
  }
  return NULL;
}

template <class S>
std::ostream &operator<<(std::ostream &out, const LinkedList<S> &list) {
  Node<T> *walker = list->_head;
  while (walker != nullptr) {
    out << walker->data;
    walker = walker->next;
  }
  return out;
}