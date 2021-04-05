/**
 * Queue - Main File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include "queue.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
  // Declare the queue
  Queue<int> q1;
  Queue<int> q2;

  // Check if the queue is empty
  cout << "If queue q1 is empty: " << q1.empty() << endl;     // 1

  // Check the queue size
  cout << "a1 current size: " << q1.size() << endl;           // 0

  // Pop and front
  q1.push(10);
  cout << "q1.push(10), "
       << "q1 current size: " << q1.size() << ", "            // 1
       << "q1.front() is: " << q1.front() << endl;            // 10
  q1.push(11);
  cout << "q1.push(11), "
       << "q1 current size: " << q1.size() << ", "            // 2
       << "q1.front() is: " << q1.front() << endl;            // 10
  q1.push(12);
  cout << "q1.push(12), "
       << "q1 current size: " << q1.size() << ", "            // 3
       << "q1.front() is: " << q1.front() << endl;            // 10
  q1.push(13);
  cout << "q1.push(13), "
       << "q1 current size: " << q1.size() << ", "            // 4
       << "q1.front() is: " << q1.front() << endl;            // 10
  q1.push(14);
  cout << "q1.push(14), "
       << "q1 current size: " << q1.size() << ", "            // 5
       << "q1.front() is: " << q1.front() << endl;            // 10
  q1.push(15);
  cout << "q1.push(15), "
       << "q1 current size: " << q1.size() << ", "            // 6
       << "q1.front() is: " << q1.front() << endl;            // 10

  // Pop the front
  q1.pop();
  cout << "q1.pop(), "
       << "q1 current size: " << q1.size() << ", "            // 5
       << "q1.front() is: " << q1.front() << endl;            // 10

  // q1 seek
  cout << "q1.seek(4): " << q1.seek(4) << endl;               // 15
  cout << "q1.seek(4): " << q1.seek(3) << endl;               // 14
  cout << "q1.seek(4): " << q1.seek(2) << endl;               // 13
  cout << "q1.seek(4): " << q1.seek(1) << endl;               // 12
  cout << "q1.seek(4): " << q1.seek(0) << endl;               // 11

  // Operator=
  q2 = q1;
  cout << "q2 = q1, q2 current size: " << q2.size() << endl;
  cout << "q2.front(): " << q2.front() << endl;

  // q2 seek
  cout << "q2.seek(4): " << q2.seek(4) << endl;               // 14
  cout << "q2.seek(3): " << q2.seek(3) << endl;               // 13
  cout << "q2.seek(2): " << q2.seek(2) << endl;               // 12
  cout << "q2.seek(1): " << q2.seek(1) << endl;               // 11
  cout << "q2.seek(0): " << q2.seek(0) << endl;               // 10
  
  return 0;
}