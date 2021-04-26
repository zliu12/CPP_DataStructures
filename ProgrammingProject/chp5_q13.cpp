#include <iostream>

class Node {
 public:
  int data;
  Node* next;
};

// use value_type to represent the node value
typedef int value_type;
class LinkedList {
 private:
  value_type data_field;
  Node* link_field;

 public:
  // Node constructor
  Node(const value_type& init_data, Node* init_link) {
    data = init_data;
    next = init_link;
  }
  // Set the data
  void setData(const value_type& value) {
    data = value;
  }
  // Set the next;
  void setNext(Node* link) {
    next = link;
  }
  // Get the next;
  Node* getNext() const {
    return next;
  }
  // Get the data
  value_type getData() const {
    return data;
  }
};