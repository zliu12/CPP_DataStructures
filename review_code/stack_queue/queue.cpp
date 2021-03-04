/**
 * Stack and Queues
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* Real Life Example of Stack
Pancakes, CDs, Textbooks, cash, cash, legos
Rule of Using Computer Stack:Last in first out (LIFO) / First in last out (FILO)
 */

/* Real Life Example of Queue
DMV lines, class waitlist, playlist
Rule of Using Computer Queue: First in first out(FIFO) */

/* class Queue 
function push: add item to the queue
function pop: take out the next item in the queue
function front: get the value at the front of the queue
function empty: return true if queue is empty, otherwise false
Queue push and pop on the oppsite side
Stack push and pop on the same side */

#include "stack.h"
#include "queue.h"
#include <string>
#include <iostream>

void Queue::push(int item) {
  list.insertTail(item);  
}

void Queue::pop() {
  list.removeHead();
}

int Queue::front() {
  return list.getHead();
}

bool Queue::empty() {
  return list.getHead() == 0;
}

bool isPalindrome(std::string word) {
  Queue q;
  Stack s;

  for (int i = 0; i < word.length(); i++) {
    q.push(word.at(i));   // Push word inside of queue
    s.push(word.at(i));   // Push word inside of stack
  }

  while (!q.empty() && !s.empty()) {
    if (q.front() != s.top()) {
      return false;
    } else {
      q.pop();
      s.pop();
    }
  }

  return true;
}

int main() {
  std::string words[] = {"radar", "tacocat", "drums"};

  for(int i = 0; i < 3; i++) {
    std::cout << words[i];
    if (isPalindrome(words[i])) {
      std::cout << " is palindrome";
    } else {
      std::cout << " is not a palindrome";
    }
    std::cout << std::endl;
  }
  return 0;
}