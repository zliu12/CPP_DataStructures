/**
 * Assignment - Dynamic Arrays.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>

class IntVector {
 private:
  int _size = 5;
  int *_ptr = new int[_size];

 public:
  void add(int);
  int get(int);
  void resize();
  int size();
};

// Function adds new integers into the dynamic array, once the array is full,
// function resize will be called to add more capacity to the dynamic array
// Precondition: index is a non-negative integer
// Postcondition: new integers are added to the dynamic array
void IntVector::add(int index) {
  if (_size > index) {
    *(_ptr + index) = index;
  } else {
    resize();
    *(_ptr + index) = index;
  }
}

// Function gets the value stored at index in dynamic array
// Precondition: index is a non-negatvie integer
// Postcondition: the value stored at index-th position in dynamic array is
// returned
int IntVector::get(int index) {
  return *(_ptr + index);
}

// Functiomaken creates a new dynamic array which has a double size of the
// original dynamic array, copies the elements of the original dynamic array
// into the new dynamic array, free the memory spaces allocated to the original
// dynamic array, makes the pointer that pointed to the original array now point
// to the new dynamic array
// Precondition: 
// Postcondition: _ptr now points to a new dynamic array that's double on size
void IntVector::resize() {
  _size = _size * 2;
  int *tmp = new int[_size];
  for (int i = 0; i < _size; i++) {
    *(tmp + i) = *(_ptr + i);
  }
  delete [] _ptr;
  _ptr = tmp;
}

int IntVector::size() {
  return _size;
}


int main() {
  IntVector vect;
  
  for (int i = 0; i < 10; i++) {
    vect.add(i);
  }

  for (int i = 0; i < vect.size(); i++) {
    std::cout << vect.get(i);
  }

  std::cout << std::endl;
  return 0;
}