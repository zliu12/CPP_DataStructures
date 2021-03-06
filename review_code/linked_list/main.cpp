#include "linked_list.h"
#include <iostream>

int main() {
  LinkedList l;
  LinkedList l2;

  for (int i = 0; i < 10; i++) {
    l.insertHead(i);
  }

  for (int i = 0; i < 10; i++) {
    l2.insertTail(i);
  }
  std::cout << l << std::endl;
  std::cout << l2 << std::endl;
  return 0;
}