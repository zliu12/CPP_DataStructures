#include <iostream>

void print(int numOfSpace, int numOfStar);

int main() {
  print(0, 8);
  
  return 0;
}

void print(int numOfSpace, int numOfStar) {
  // Return if the num of asterisks is zero
  if (numOfStar == 0) {
    return;
  }

  // The number of asterisks starts from 8 (the middle line), call print again
  // with the half of asterisks, then call print again with the half of
  // asterisks, and so on. (8, 4, 2, 1, 0)
  print(numOfSpace, numOfStar / 2);

  for (int i = 0; i < numOfSpace; i++) {
    std::cout << "  ";
  }

  for (int i = 0; i < numOfStar; i++) {
    std::cout << "* ";
  }

  std::cout << std::endl;

  // Since the max number of starts in one row is 8, call print again to print
  // out the bottom half, the number of asterisks is the same with the upper
  // half
  print(numOfSpace + (numOfStar / 2), (numOfStar / 2));
}