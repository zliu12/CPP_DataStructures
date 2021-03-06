/**
 * Const_Static Main file
 *
 * Copyright (c) [2021], Zhao Liu.
 */
#include <iostream>
#include "const_static.h"

static int count = 0;

int main() {
  std::cout<< Inventory::getCount() << std::endl;
  Inventory i1;
  std::cout << Inventory::getCount() << std::endl;
  Inventory i2;
  std::cout << Inventory::getCount() << std::endl;
  for (int i = 0; i < 10; i++) {
    Inventory inventory;
  }
  std::cout << Inventory::getCount() << std::endl;

  return 0;
}