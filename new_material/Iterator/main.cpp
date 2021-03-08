/**
 * Iterators
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <vector>
#include <iostream>

int main() {
  std::vector<int> v;
  std::vector<int>::iterator iter;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }

  for (iter = v.begin(); iter != v.end(); iter++) {

    std::cout << *iter << std::endl;
  } 
  return 0;
}