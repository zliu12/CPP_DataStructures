#include "linked_list.h"
#include "Node_Iterator.h"
#include <iostream>

int main() {
  // Declare the list
  LinkedList<int> list;

  // Add to the list
  for (int i = 0; i < 10; ++i) {
    list.insertTail(i);
  }

  // Declare the Node Iterator
  Node_Iterator<int> iter1 = list.begin();
  Node_Iterator<int> iter2 = list.end();

  while (iter1 != list.end()) {
    std::cout << *iter1 << " ";
    ++iter1;
  }
  std::cout << std::endl;
  while (iter2 != list.begin()) {
    std::cout << *iter2 << " ";
    --iter2;
  }


  return 0;
}
