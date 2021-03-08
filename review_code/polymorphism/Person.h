/**
 * Person Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <string>

class Person {
 private:
  std::string firstName, lastName;

 public:
  Person();
  Person(std::string firstName, std::string lastName);
  void print();
};