#ifndef MATH_H_
#define MATH_H_
#include <cmath>
#include <exception>
#include <string>

class DivideByZeroExcpetion : public std::exception {
 private:
  std::string message;

 public:
  DivideByZeroExcpetion();
  DivideByZeroExcpetion(char* message);
  // noexcept means we promise we not gonna throw exception
  virtual const char* what() const noexcept;

};

class NegativeNumberExcpetion : public std::exception {
 public:
  virtual const char* what() const noexcept;
};

class Math {
 public:
  static double divide(double numerator, double denominator);
  static double sqrt(double number);
};


#endif  // MATH_H_