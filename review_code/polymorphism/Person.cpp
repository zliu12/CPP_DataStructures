/**
 * Person Implementation File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>
#include "Person.h"

Person::Person() {
  
}

Person::Person(std::string firstName, std::string lastName) : firstName(firstName) {
  this->lastName = lastName;
}

void Person::print() {
  std::cout << firstName << " " << lastName;
}