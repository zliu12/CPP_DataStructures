/**
 * CS008 - CS003A Review3 - Linked List.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* 
Pointer created inside the function is auto-deleted once the function exits,
but the memory allocated is not, so we have to manually delete it.
*/

class Node {
 private:
  int _data;
  Node *next;
};

class LinkedList {
 private:
  Node *_head;
 public:
  ~LinkedList() {
    while (_head != nullptr) {
      std::cout << *this << std::endl;
      remove(_head);
    }
  }

  // copy constructor
  LinkedList(const LinkedList &list) {
    // (*this).operator=(list);
    *this = list;
  }

  LinkedList &operator=(const LinkedList &list) {
    if (this == &list) {
      return *this;
    }

    this->~LinkedList();
    Node *walker = list._head;
    while (walker != nullptr) {
      insertTail(walker->data);
      walker = walker->next;
    }
    return *this;
  }
};
