/**
 * Heap - Header
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>
#include <vector>

template<class T>
class Heap {
 private:
  // Hold values of heap
  // This is the underlying data structure to hold all data
  std::vector<T> dataVec;

  // Recursion
  // If the root is less than the child, then it's going to swap with the
  // largest child value that's greater than the root, recursively.
  void heapifyDown(int parentIdx);

  // Easier with iteration
  // This will iteratively move the child up the tree until it finds it's
  // proper position
  // as long as bigger than parent, keep going up along the tree unless less
  // than the parent.
  void heapifyUp(int childIdx);

  // Swap two data
  void swap(T& a, T& b);

  // Return the index of the parent
  int getParentIdx(int childIdx);

  // Return left child of the data
  // leftchildIdx = parent * 2 + 1;
  int getLeftChildIdx(int parentIdx);

  // Return right child of the data
  // rightchildIdx = parent * 2 + 2;
  int getRightChildIdx(int parentIdx);

 public:
  // Remove the highest priority item of the priority queue
  // Remove the root node, then heapify downward
  // Swap the root of the tree, with the last element in the tree
  // Remove the last element in the tree
  // Heapify down
  void pop();

  // Return the highest priority item of the queue (without removing it)
  // if there are several equally high priorities, the implementation may
  // decide which one to return
  // Return the root node
  T top();

  // Add an item to the priority queue
  // Add node to the tree, then heapify up
  void push(T data);

  // Add an item to the heap
  void operator+=(const T data);

  // Return the number of items in the queue
  // Return the number of items in the tree
  int getSize();

  // Return true if the queue is empty (otherwise return false)
  // Return true if the tree has no elements, otherwise false
  bool empty();
};

#include "Heap.cpp"
#endif  // HEAP_H_