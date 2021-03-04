/**
 * Template - LinkedList Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* What is a template
void swap(int &a, int &b) {
  int temp(a);
  a = b;
  b = temp;
}

void swap(char &a, char &b) {
  char temp(a);
  a = b;
  b = temp;
}

void swap(double &a, double &b) {
  double temp(a);
  a = b;
  b = temp;
}

void swap(float &a, float &b) {
  float temp(a);
  a = b;
  b = temp;
}

// T will substitute a data type, adapt to the variable type
template <class T>
void swap(T &a, T &b) {
  T temp(a);
  a = b;
  b = temp;
}

int main() {
  std::string a = "hello", b = "world";
  float f1 = 1.f, f2 = 2.f;

  swap(a, b);   // T turns to string
  swap(f1, f2);   // T turns to float
}
 */

#ifndef TMPLT_LL_H_
#define TMPLT_LL_H_
#include "Tmplt_ND.h"
#include <iostream>
#include <string>

template <class T>
class LinkedList {
 private:
  Node<T> *_head = nullptr;
  Node<T> *_tail = nullptr;
  void insertFirst(T item);
  Node<T> *createNode(T item);
  Node<T> *find(T item);
  void remove(Node<T> *node_remove);
  Node<T> *prevNode(Node<T> *node_remove);

 public:
  void insertHead(T item);
  void insertTail(T item);
  void remove(T item);
  void removeHead();
  T get_head();

  template <class S>
  friend std::ostream &operator<<(std::ostream &out, const LinkedList<S> &list);
};


#endif    // TMPLT_LL_H_