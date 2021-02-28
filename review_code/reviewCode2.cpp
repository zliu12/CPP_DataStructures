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
  Node *createNode(int item);   // Create a new node
  Node *find(int item);   // Find the node with the number item in it
  /* Overload the remove function so that we can remove that particular node
  that we find, so it has node as the parameter */
  void remove(Node *node);
  Node *previousNode(Node *node);

 public:
  void insertHead(int item);
  void insertTail(int item);
  /* Call find to find the node with the value in it, then pass that node to the
  remove(Node *node) function and the remove function will do the removing 
  process */
  void remove(int item);
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

std::ostream &operator<<(std::ostream &out, const LinkedList &list) {
  Node *walker = list._head;
  while (walker != nullptr) {
    out << walker->data;
    walker = walker->next;
  }
  return out;
}

Node* LinkedList::createNode(int item) {
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
  while (walker->data != item && walker != _tail->next) {
    walker = walker->next;
  }
  return walker;
}

// Function remove is overloaded
// 1.Walker settles at the node prior to the target(remove) node
// 2.Pt walker->next to remove's next, now the remove node is isolated
// 3.Delete remove
// if (head = nullptr): nothing in the list thus just return
// if (head = tail): only 1 element, make head/tail = nullptr, delete walker
// if (remove = tail): make tail = walker, tail->next = nullptr, delete remove
// if (remove = head), head = head->next, delete remove 
void LinkedList::remove(Node *node_remove) {
  // walker generally "stays" at the node prior to the target(remove) node
  Node *node_prior = previousNode(node_remove);
  if (node_remove == nullptr) {
    /* If the target is a nullptr? */
    return;   // Can't look for a 'nothing', return
  }
  if (_head == nullptr) {
    /* If list empty? Head = NULL means nothing in the list */
    return;   // Nothing in the list, return
  } else if (_head == _tail) {  /* Only 1 element? head = tail mean they both
    pt to the same address which indicate the list has 1 element only */
    _head = nullptr;  // Set head pts to NULL
    _tail = nullptr;  // Set tail pts to NULL
    delete node_prior;    // delete walker since no use
  } else if (node_remove == _tail) {  /* Remove the last node(tail)? */
    _tail = node_prior;     // Let tail pt to the second to last node(new tail)
    delete node_remove;     // Delete the target node (the original last node)
    _tail->next = nullptr;  // Let the new last node's ptr var pt to nullptr
  } else if (node_remove == _head) {  /* Remove the first node(head)? */
    _head = _head->next;  // Let head pt to the second node(new head)
    delete node_remove;   // Delete the target node(the original first node)
  } else {  /* Remove node in the middle? */
    node_prior->next = node_remove->next; /* Let the ptr var of the node prior to
    the target node pts to the address which's pointed by the ptr var of target
    node, the target node now is isolated */
    delete node_remove;   // Delete the target node
  }
}

void LinkedList::remove(int item) {
  remove(find(item));
}

Node* LinkedList::previousNode(Node *node) {
  Node *walker = _head;
  // when walker not pts to the nullptr(_tail->next) && walker not pts to the
  // target node (which walker pts to the node prior to the target node)
  while (walker != nullptr && walker->next != node) {
    walker = walker->next;
  }
  return walker;
}

int main() {
  LinkedList l;
  LinkedList l2;
  for (int i = 0; i < 10; i++) {
    l.insertTail(i);
  }
  std::cout << "l insert head: ";
  std::cout << l << std::endl;
  
  for (int i = 0; i < 10; i++) {
    l2.insertHead(i);
  }
  std::cout << "l2 insert tail: ";
  std::cout << l2 << std::endl;

  l2.remove(0);
  std::cout << "remove l2 - 0: " << l2 << std::endl;
  l2.remove(5);
  std::cout << "remove l2 - 5: " << l2 << std::endl;
  l2.remove(9);
  std::cout << "remove l2 - 9: " << l2 << std::endl;

  return 0;
}