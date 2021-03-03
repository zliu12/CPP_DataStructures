#ifndef MATH_CPP_
#define MATH_CPP_
#include "math.h"
#include <cmath>


double Math::divide(double numerator, double denominator) {
  if (denominator == 0) {
    throw DivideByZeroExcpetion();
  }
  return numerator / denominator;
}

double Math::sqrt(double number) {
  if (number < 0) {
    throw NegativeNumberExcpetion();
  }
  return std::sqrt(number);
}

const char* DivideByZeroExcpetion::what() const noexcept {
  return "Cannot divide by zero";
}

const char* NegativeNumberExcpetion::what() const noexcept {
  return "Number must be greater than zero";
}

DivideByZeroExcpetion::DivideByZeroExcpetion() {}
DivideByZeroExcpetion::DivideByZeroExcpetion(char* message) {
   
}
#endif  // MATH_CPP_