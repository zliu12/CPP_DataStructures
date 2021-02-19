/**
 * CS008 - CS003A Review.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* Pointer 
1. A var stores a memory address
2. Pointing to a var at that address
3. Using asterisk, i = 5; int*ip = &i;
4. Deferencing: get the value of our ptr and then go to that address and make
   changes (or retrieve)
5. Change the value: *ip = 10 (change from 5 to 10)
6. int *p = new int: creat a space on free store, delete p;
7. Dynamic array: int *ap = new int[10]; delete [] ap;
*/

#include <iostream>

int main() {
  // declare two in variables
  int num1 = 5;
  int num2 = 6;
  std::cout << "num1: " << num1 << std::endl;   // num1 = 5
  std::cout << "num2: " << num2 << std::endl;   // num2 = 6

  int *p1 = &num1;
  int *p2 = &num2;
  std::cout << "*p1: " << *p1 << std::endl;   // *num1p = 5
  std::cout << "*p2: " << *p2 << std::endl;   // *num2p = 6

  p1 = p2;
  std::cout << "*num1p: " << *p1 << std::endl;   // *num1p = 6
  std::cout << "*num2p: " << *p2 << std::endl;   // *num2p = 6
  std::cout << "num1: " << num1 << std::endl;    // num1 = 5
  std::cout << "num2: " << num2 << std::endl;    // num2 = 6
 
  *p1 = 90;
  std::cout << "num1: " << num1 << std::endl;
  std::cout << "num2: " << num2 << std::endl;
}