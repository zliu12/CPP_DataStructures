/**
 * Heap - Implementation
 * Copyright (c) [2021], Zhao Liu.
 *
 */

#ifndef HEAP_CPP_
#define HEAP_CPP_

#include "Heap.h"

// Recursion
// If the root is less than the child, then it's going to swap with the
// largest child value that's greater than the root, recursively.
template<class T>
void Heap<T>::heapifyDown(int parentIdx) {
  // Find left and right children idx of node parentIdx
  int leftChildIdx = getLeftChildIdx(parentIdx);
  int rightChildIdx = getRightChildIdx(parentIdx);

  // Check if data at parentIdx has node children
  if (leftChildIdx > getSize() || rightChildIdx > getSize()) {
    // std::cout << "Index " << parentIdx << " has no node children." << std::endl;
    return;
  }

  // Create a temporary prior data idx, set it to parentIdx
  int tempPriorIdx = parentIdx;

  // Compare the priority of data at parentIdx, data at lefChildIdx, data at
  // rightChildIdx, assign the idx of the highes priority data to tempPriorIdx
  // left >= parent, temp = left
  if (leftChildIdx < getSize() && dataVec.at(leftChildIdx) > dataVec.at(parentIdx)) {
    tempPriorIdx = leftChildIdx;
  }

  // right >= temp, temp = right
  if (rightChildIdx < getSize() && dataVec.at(rightChildIdx) > dataVec.at(tempPriorIdx)) {
    tempPriorIdx = rightChildIdx;
  }

  // If data at parent is not the largest
  if (tempPriorIdx != parentIdx) {
    // Swap the data at parentIdx with the data at tempPriorIdx
    swap(dataVec.at(parentIdx), dataVec.at(tempPriorIdx));
    // Now the data at tempPriorIdx is the data from parentIdx, heapify down again
    heapifyDown(tempPriorIdx);
  }
}

// Easier with iteration
// This will iteratively move the child up the tree until it finds it's
// proper position
// as long as bigger than parent, keep going up along the tree unless less
// than the parent.
template<class T>
void Heap<T>::heapifyUp(int childIdx) {
  // If the childIdx is 0, return
  if (childIdx == 0) {
    // std::cout << "Index " << childIdx << " has nothing on top." << std::endl;
    return;
  }

  // Find the idx of parent
  int parentIdx = getParentIdx(childIdx);

  // If the data at childIdx > the data at parentIdx
  if (dataVec.at(childIdx) > dataVec.at(parentIdx)) {
    // Swap the  data at childIdx with the data at parentIdx
    swap(dataVec.at(childIdx), dataVec.at(parentIdx));
    // Now the data at parentIdx is the data from childIdx, heapify up again
    heapifyUp(parentIdx);
  }
}

// Swap two data
template<class T>
void Heap<T>::swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

// Return the index of the parent
template<class T>
int Heap<T>::getParentIdx(int childIdx) {
  return (childIdx - 1) / 2;
}

// Return left child of the data
// leftChildIndex = parent * 2 + 1;
template<class T>
int Heap<T>::getLeftChildIdx(int parentIdx) {
  return parentIdx * 2 + 1;
}

// Return right child of the data
// rightChildIndex = parent * 2 + 2;
template<class T>
int Heap<T>::getRightChildIdx(int parentIdx) {
  return parentIdx * 2 + 2;
}

// Remove the highest priority item of the priority queue
// Remove the root node, then heapify downward
// Swap the root of the tree, with the last element in the tree
// Remove the last element in the tree
// Heapify down
template<class T>
void Heap<T>::pop() {
  // If no data
  if (getSize() == 0) {
    std::cout << "No data, nothing to pop." << std::endl;
  }

  // Move the last node to the root
  dataVec.at(0) = dataVec.back();
  // Data at root now is the same with data at the last idx, so pop the data at
  // the last idx
  dataVec.pop_back();
  // Check if the data at root follows the heap rule
  heapifyDown(0);
}

// Return the highest priority item of the queue (without removing it)
// if there are several equally high priorities, the implementation may
// decide which one to return
// Return the root node
template<class T>
T Heap<T>::top() {
  // If no data
  if (getSize() == 0) {
    std::cout << "No data, nothing at the top." << std::endl;
    return 0;
  }
  else {
    return dataVec.at(0);
  }
  return 0;
}

// Add an item to the priority queue
// Add node to the tree, then heapify up
template<class T>
void Heap<T>::push(T data) {
  // Add new data at the end of the vector
  dataVec.push_back(data);

  // Relocate the new added data to correct idx
  int newDataIdx = getSize() - 1;
  heapifyUp(newDataIdx);
}

// Add an item to the heap
template<class T>
void Heap<T>::operator+=(const T data) {
  push(data);
}

// Return the number of items in the queue
// Return the number of items in the tree
template<class T>
int Heap<T>::getSize() {
  return dataVec.size();
}

// Return true if the queue is empty (otherwise return false)
// Return true if the tree has no elements, otherwise false
template<class T>
bool Heap<T>::empty() {
  return dataVec.size() == 0;
}


#endif  // HEAP_CPP_