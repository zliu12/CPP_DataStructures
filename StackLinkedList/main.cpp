/**
 * Stack - Main File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include "stack.h"
#include <iostream>

int main() {
  // Declare the stack
  Stack<int> s1;
  Stack<int> s2;

  // Check if the stack is empty
  std::cout << "If stack s1 is empty: " << s1.empty() << std::endl;   // 1
  
  // Check the stack size
  std::cout << "s1 current size: " << s1.size() << std::endl;         // 0

  // Push and top
  s1.push(10);
  std::cout << "s1.push(10), " 
            << "s1 current size: " << s1.size() << ", "             // 1  
            << "s1.top() is: " << s1.top() << std::endl;            // 10

  s1.push(11);
  std::cout << "s1.push(11), "
            << "s1 current size: " << s1.size() << ", "             // 2 
            << "s1.top() is: " << s1.top() << std::endl;            // 11

  s1.push(12);
  std::cout << "s1.push(12), "
            << "s1 current size: " << s1.size() << ", "             // 3  
            << "s1.top() is: " << s1.top() << std::endl;            // 12

  s1.push(13);
  std::cout << "s1.push(13), "
            << "s1 current size: " << s1.size() << ", "             // 4  
            << "s1.top() is: " << s1.top() << std::endl;            // 13

  s1.push(14);
  std::cout << "s1.push(14), "
            << "s1 current size: " << s1.size() << ", "             // 5  
            << "s1.top() is: " << s1.top() << std::endl;            // 14

  s1.push(15);
  std::cout << "s1.push(15), "
            << "s1 current size: " << s1.size() << ", "             // 6  
            << "s1.top() is: " << s1.top() << std::endl;            // 15

  // Pop the top
  s1.pop();
  std::cout << "s1.pop(), "
            << "s1 current size: " << s1.size() << ", "             // 5
            << "s1.top() is: " << s1.top() << std::endl;            // 14

  std::cout << "s1.seek(4): " << s1.seek(4) << std::endl;           // 10
  std::cout << "s1.seek(3): " << s1.seek(3) << std::endl;           // 11
  std::cout << "s1.seek(2): " << s1.seek(2) << std::endl;           // 12
  std::cout << "s1.seek(1): " << s1.seek(1) << std::endl;           // 13
  std::cout << "s1.seek(0): " << s1.seek(0) << std::endl;           // 14

  // operator =
  s2 = s1;
  std::cout << "s2.top(): " << s2.top() << std::endl;
  std::cout << "s2 = s1, s2 current size: " << s2.size() << std::endl;

  std::cout << "s2.seek(4): " << s2.seek(4) << std::endl;           //
  std::cout << "s2.seek(3): " << s2.seek(3) << std::endl;           //
  std::cout << "s2.seek(2): " << s2.seek(2) << std::endl;           //
  std::cout << "s2.seek(1): " << s2.seek(1) << std::endl;           //
  std::cout << "s2.seek(0): " << s2.seek(0) << std::endl;           //

  return 0;
}