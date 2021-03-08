/**
 * CS008 - CS003A Review2 - Linked List.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* What is linked likst
1. A data structure, nodes pointing to other nodes, a way to store data, linear,
no random access(sequential), have both data and ptrs, doubly linked list(you
can traverse forward/backward), circular(make the end ptr to the beginning)¡
2. What you need for linked list class
  head -> node ptr 
    points to the beginning of the list
  tail -> node ptr
    points to the end of the list
 */

/* When the first node is added
1. Create a new node:
  a. head = new node;
  b. tail = head;
  c. head->data = 0;
2. Add a node into the end of linked list
  a. create a new node
  b. let head -> next points to the new node: head->next = new node;
  c. update tail: tail = new node;
 */

/* When there are one or more nodes in the linked list
1. Create a new node:
  a-1. tail->next = new node;
  a-2. Node *n = new node;
  b. tail->next = n;
  c-1. tail = n;
  c-2. tail = tail->next;
 */

/* When add a node into the beginning of the list
1. if list is empty
  a. head points to new node, tail points to new node
2. if list is not empty
  a. create a new node: Node *np = new node;
  b. new node ptr points to head: np->next = head
  c. head points to np
 */

/* When deleting a node
1. create a walker: Node *walker = head;
2. for (Node *walker = head; walker->next != search && walker->next != nullptr;
        walker = walker->next) {walker = walker->next};
3. walker->next = search->next;
   search->next = nullptr;
4. delete search;
 */

#include "linked_list.h"
#include <iostream>


Node* LinkedList::createNode(int item) {
  // A new node is created somewhere on the memory, when get out the function
  // scope, the ptr (local var n) gets deleted, but the memory allcoated for
  // the new node gets remained on the memory although the ptr is deleted
  Node *n = new Node;
  n->data = item;
  n->next = nullptr;
  return n;
}

Node* LinkedList::find(int item) {
  // Create a walker pts the same memory address as the head
  Node *walker = _head;
  // Approach 1
  // As long as the walker hasn't reached the nullptr(_tail->next), by making
  // walker = walker->next (walker->next is the ptr var of the node that walker
  // pts to), walker moves along the list
  // while (walker != _tail->next) {
  //   walker = walker->next;
  //   // When walker finds a node that its data val equals the item, return
  //   if (walker->data == item) {
  //     return walker;
  //   }
  // }
  // return nullptr;

  // Approach 2
  // Must check walker != _tail->next first bcuz it would be nonsense to check
  // if walker->dat != item when walker == nullptr, otherwise the program crash
  while (walker != _tail->next && walker->data != item) {
    walker = walker->next;
  }
  return walker;
}

Node* LinkedList::previousNode(Node *node_target) {
  Node *walker = _head;
  // when walker not pts to the nullptr(_tail->next) && walker not pts to the
  // target node (which walker pts to the node prior to the target node)
  while (walker != nullptr && walker->next != node_target) {
    walker = walker->next;
  }
  return walker;
}

void LinkedList::insertFirst(int item) {
  Node *n = new Node;
  n->data = item;
  _tail = n;
  _head = n;
}

// Function remove is overloaded
// 1.Walker settles at the node prior to the target(remove) node
// 2.Pt walker->next to node_remove->next, now the remove node is isolated
// 3.Delete node_remove
// if (head = nullptr): nothing in the list thus just return
// if (head = tail): only 1 element, make head/tail = nullptr, delete walker
// if (remove = tail): make tail = walker, tail->next = nullptr, delete remove
// if (remove = head), head = head->next, delete remove 
void LinkedList::remove(Node *node_target) {
  // Check if the node_target is nullptr
  if (node_target == nullptr) {
    return;
  } else {
    // Check if list is empty
    if (_head == nullptr) {
      return;
    } 
    // Check if list only has 1 member
    else if (_head == _tail) {
      _head = _tail = nullptr;
      // delete node_target;
    }
    // Check if node_target is the head
    else if (node_target == _head) {
      _head = _head->next;
      delete node_target;
    }
    // Check if node_target is the tail
    else if (node_target == _tail) {
      _tail = previousNode(node_target);
      _tail->next = nullptr;
      delete node_target;
    }
    // If node_tarfet is in the middle
    else {
      Node *prevNode = previousNode(node_target);
      prevNode->next = node_target->next;
      delete node_target;
    }
  }
}

LinkedList::LinkedList() : _head(nullptr), _tail(nullptr) {
  // std::cout << "Constructor starts" << std::endl;
  // std::cout << "Constructor ends" << std::endl;
}

// The destructor automatically gets called by the compiler when the life of the 
// var is over, not just when teh program ends
LinkedList::~LinkedList() {
  // std::cout << "Destructor starts" << std::endl;
  while (_head != nullptr) {
    // std::cout << *this << std::endl;
    remove(_head);
  }
  // std::cout << "~LinkedList() ends" << std::endl;
}

LinkedList::LinkedList(const LinkedList &list) : LinkedList() {
  /* Call the assignment operator and perform its algorithm 
  same with: (*this).operator = (list), calling the member func of the obj and
  and passing list as a variable
   */
  // std::cout << "Copy constructor starts" << std::endl;
  // Here I tell the compiler: make me a new obj by copying from list
  *this = list;   // (*this).operator=(list);
  // std::cout << "Copy constructor ends" << std::endl;
}

LinkedList& LinkedList::operator=(const LinkedList &list) {
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
  Node *walker = list._head;
  while (walker != nullptr) {
    insertTail(walker->data);
    walker = walker->next;
  }
  // std::cout << "Assignment operator ends" << std::endl;
  return *this;
}

void LinkedList::insertHead(int item) {
  if (_head == nullptr) {
    insertFirst(item);
  } else {
    Node *n = createNode(item);
    n->next = _head;
    _head = n;
  }
}

void LinkedList::insertTail(int item) {
  // If the header ptr points to null, it means nothing is in the list, so we
  // just simply insert the item and make the item the one and only element in
  // the list
  if (_head == nullptr) {
    insertFirst(item);
  } else {
    // Create a new node
    Node *n = createNode(item);
    // Tail still pting to the last node of the list rn, so tail->next denotes
    // the ptr var of the last node, by making it point to n, we're pting the 
    // last node to n, so the original last node becomes the second node to last
    // and n now becomes the last node
    _tail->next = n;
    // Pting tail to n since n's been the last node
    _tail = n;
  }
}

void LinkedList::remove(int item) {
  remove(find(item));
}

void LinkedList::removeHead() {
  remove(_head);
}

int LinkedList::getHead() {
  if (_head != nullptr) {
    return _head->data;
  }
  return 0;
}

std::ostream &operator<<(std::ostream &out, const LinkedList &list) {
  Node *walker = list._head;
  while (walker != nullptr) {
    out << walker->data;
    walker = walker->next;
  }
  return out;
}