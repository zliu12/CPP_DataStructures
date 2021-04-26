#include <iostream>

struct Node {
  int data;
  Node* next = nullptr;
};

class LinkedList {
 private:
  Node* head;
  Node* tail;
  // Create a new Node that its data = num
  Node* createNode(int num) {
    Node* n = new Node;
    n->data = num;
    n->next = nullptr;
    return n;
  }

  // Find a Node with the target value
  Node* findNode(int targetValue) {
    Node* n = head;
    while(n != nullptr && n->data != targetValue) {
      n = n->next;
    }
    return n;
  }

  // Find a Node before the Node with the target value
  Node* findPrevious(int targetValue) {
    Node* targetNode = findNode(targetValue);
    Node* n = head;
    while (n != nullptr && n->next != targetNode) {
      n = n->next;
    }
    return n;
  }

  // Fine a Node after the Node with the target value
  Node* findAfter(int targetValue) {
    Node* targetNode = findNode(targetValue);
    Node* n = head;
    while(n != nullptr && n != targetNode->next) {
      n = n->next;
    }
    return n;
  }
 
 public:
  // Insert a Node with data = num
  void insertFirst(int num) {
    Node* n = createNode(num);
    head = n;
    tail = n;
  }

  // Insert a Node at the beginning
  void insertBegin(int num) {
    // if list is empty
    if (head == nullptr) {
      insertFirst(num);
    } else {
      Node* n = createNode(num);
      n->next = head;
      head = n;
    }
  }

  // Insert a Node at the end
  void insertEnd(int num) {
    // if list is empty
    if (head == nullptr) {
      insertFirst(num);
    } else {
      Node* n = createNode(num);
      tail->next = n;
      tail = n;
    }
  }

  // Insert a value before a particular value
  void insertBeforeValue(int insertValue, int targetValue) {
    // Find the Node with the targetValue
    Node* n_target = findNode(targetValue);
    // Find the Node before the Node with the targetValue
    Node* n_prev = findPrevious(targetValue);
    // Create a Node with the insertValue
    Node* n_insert = createNode(insertValue);
    // Link n_prev with n_insert
    n_prev->next = n_insert;
    // Link n_insert with the Node with targetvalue
    n_insert->next = n_target;
  }

  // Insert a value after a particular value
  void insertAfterValue(int insertValue, int targetValue) {
    // Find the Node with the targetValue
    Node* n_target = findNode(targetValue);
    // Find the Node after the Node with the targetValue
    Node* n_after = findAfter(targetValue);
    // Create a Node with the insertvalue
    Node* n_insert = createNode(insertValue);
    // Link n_target with n_insert
    n_target->next = n_insert;
    // Link n_insert with n_after
    n_insert->next = n_after;
  }

  // Overload the += operator
  void operator+=(int targetValue) {
    insertEnd(targetValue);
  }

  // Print out the Node's data
  friend std::ostream& operator<<(std::ostream& out, const LinkedList& l) {
    for (Node* n = l.head; n != nullptr; n = n->next) {
      out << n->data;
    }
    return out;
  }
};
