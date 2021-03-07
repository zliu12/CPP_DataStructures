#include "linked_list.h"
#include <iostream>

int main() {
  LinkedList l1;
  LinkedList l2;

  for (int i = 0; i < 10; i++) {
    l1.insertHead(i);
  }

  for (int i = 0; i < 10; i++) {
    l2.insertTail(i);
  }
  std::cout << l1 << std::endl;
  std::cout << l2 << std::endl;
  
  return 0;
}