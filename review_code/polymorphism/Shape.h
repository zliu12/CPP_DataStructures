/**
 * Shape Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

class Shape {
 public:
  // This is a pure virtual function, no need to implement in Shape.cpp, but in
  // all other derived class who uses this function
  virtual double getArea() = 0;
};