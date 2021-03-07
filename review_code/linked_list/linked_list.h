/**
 * Linked List Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "node.h"
#include <iostream>

class LinkedList {
 private:
  Node *_head;
  Node *_tail;
  // Create a new node
  Node *createNode(int item); 

  // Find the node with the number item in it
  Node *find(int item);
  Node *previousNode(Node *node_target);

  // Only call this when find head and tail are NULL
  void insertFirst(int item);

  /* Overload the remove function so that we can remove that particular node
  that we find, so it has node as the parameter */
  void remove(Node *node_target);

 public:
  // Default constructor
  LinkedList();
  // A destructor has the same name as the class, with a tilde in the front
  ~LinkedList();                                  // Big3: Destructor                              
  LinkedList(const LinkedList &list);             // Big3: Copy constructor
  LinkedList &operator=(const LinkedList &list);  // Big3: Assignment operator
  void insertHead(int item);
  void insertTail(int item);

  /* Call find to find the node with the value in it, then pass that node to the
  remove(Node *node) function and the remove function will do the removing 
  process */
  void remove(int item);
  void removeHead();
  int getHead();
  friend std::ostream &operator<<(std::ostream &out, const LinkedList &list);
};


#endif    // LINKED_LIST_H_