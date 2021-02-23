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

#include <iostream>

struct Node {
  int data;
  Node *next = nullptr;
};

class LinkedList {
 private:
  Node *_head;
  Node *_tail;
  void insertFirst(int item);

 public:
  void insertHead(int item);
  void insertTail(int item);
  friend std::ostream &operator<<(std::ostream &out, const LinkedList &list);
};

void LinkedList::insertFirst(int item) {
  Node *n = new Node;
  n->data = item;
  _tail = n;
  _head = n;
}

void LinkedList::insertHead(int item) {
  if (_head == nullptr) {
    insertFirst(item);
  } else {
    Node *n = new Node;
    n->data = item;
    n->next = _head;
    _head = n;
  }
}

void LinkedList::insertTail(int item) {

}

std::ostream &operator<<(std::ostream &out, const LinkedList &list) {
  Node *walker = list._head;
  while (walker != nullptr) {
    out << walker->data;
    walker = walker->next;
  }

  return out;
}

int main() {
  LinkedList l;
  for (int i = 0; i < 10; i++) {
    l.insertHead(i);
  }
  std::cout << l << std::endl;
}