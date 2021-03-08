/**
 * Inheritance
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* Inheritance
1. Derive a child class that inherits all of its parents member vars and member
  functions */

class Parent {
 private:
  int x;
  int f();

 public:
  int getX();
  void setX(int x);
};

class child : public Parent {};