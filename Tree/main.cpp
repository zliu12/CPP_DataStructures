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

  std::cout << "This is the data: ";
  for(int i = 0; i < 10; ++i) {
    int x = rand() % 100;
    std::cout << x << " ";
    t.push(x);
  }
  std::cout << std::endl;

  std::cout << "inOrder tree: ";
  t.inOrder();
  std::cout << std::endl;

  std::cout << "Double tree: ";
  t.inOrder(doubleTree);
  return 0;
}

void doubleTree(int& item) {
  item *= 2;
  // std::cout << "Double tree called" << std::endl;
}