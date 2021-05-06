/**
 * Main File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>
#include <ctime>
#include "BinaryTree.h"

void doubleTree(int& item);

int main() {
  srand(time(NULL));
  BinaryTree<int> t;

  std::cout << "Numbers: " << std::endl;
  for(int i = 0; i < 10; ++i) {
    int x = rand() % 50;
    std::cout << x << "\t";
    // t.push(x);
    t += x;
  }
  std::cout << std::endl;

  std::cout << "inOrder: " << std::endl;
  t.inOrder();
  std::cout << std::endl;

  std::cout << "inOrder*2: " << std::endl;
  t.inOrder(doubleTree);
  t.inOrder();
  return 0;
}

void doubleTree(int& item) {
  item *= 2;
  // std::cout << "Double tree called" << std::endl;
}