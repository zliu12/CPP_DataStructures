#include <iostream>
#include <ctime>
#include "Heap.h"

int main() {
  srand(time(NULL));
  Heap<int> h;

  // Empty
  if (h.empty()) {
    std::cout << "The binary heap is empty" << std::endl;
  }

  // Add data
  std::cout << "Data added: ";
  for (int i = 0; i < 10; ++i) {
    int dataAdded = rand() % 20;
    std::cout << dataAdded << " ";
    // h.push(dataAdded);
    h += dataAdded;           // Will call push function
  }
  std::cout << std::endl;

  // Size
  std::cout << "h size: " << h.getSize() << std::endl;

  // Top
  std::cout << "h top: " << h.top() << std::endl;

  // Pop
  h.pop();
  std::cout << "h top after pop: " << h.top() << std::endl;

  return 0;
}