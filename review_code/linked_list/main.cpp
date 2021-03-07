#include "linked_list.h"
#include <iostream>

void proofOfDestructor(LinkedList);

int main() {
  std::cout << "Create l2" << std::endl;
  LinkedList l2;
  std::cout << "Going to call proofOfDestructor(l2)\n";
  proofOfDestructor(l2);
  std::cout << std::endl;

  std::cout << "In main, l2 insertTail starts" << std::endl;
  for (int i = 0; i < 10; i++) {
    l2.insertTail(i);
  }
  std::cout << "In main, l2 insertTail ends: " << l2 << std::endl << std::endl;

  std::cout << "Create l3 from l2" << std::endl;
  LinkedList l3 = l2;
  std::cout << "l3(l2): " << l3 << std::endl << std::endl;

  // LinkedList l1;
  // for (int i = 0; i < 10; i++) {
    // l1.insertHead(i);
  // }
  // std::cout << "l1 insert to tail: " << l1 << std::endl;
  // l1.remove(0);
  // std::cout << "l1 remove 0 (head): " << l1 << std::endl;
  // l1.remove(9);
  // std::cout << "l1 remove 9 (tail): " << l1 << std::endl;
  // l1.remove(5);
  // std::cout << "l1 remove 5 (middle): " << l1 << std::endl;
  // l1.remove(10);
  // std::cout << "l1 remove 10 (not in list): " << l1 << std::endl;

  return 0;
}

void proofOfDestructor(LinkedList l2) {
  std::cout << "In proofOfDestructor, l2 starts insertTail" << std::endl;
  for (int i = 0; i < 10; i++) {
    l2.insertTail(i);
  }
  std::cout << "In proofOfDestructor, l2 done insertTail: " << l2 << std::endl;
  std::cout << "Func proofOfDestructor ends here, call ~LinkedList() next.\n";
}