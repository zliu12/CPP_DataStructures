/**
 * Exception Handling
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* Error Handling
1. Exit program
  a. assert from <cassert>
  b. exit(some code here)
2. Handle the error with defaults
3. Loop until the user put in the correct data
 */

/* Exception Handling
try/catch
double divide(double a, double b) {
  if (b == 0) {
    throw "b can't be zero";
  }
  return a/b;
}
try {
  // do sth
  double x = divide(5, 0);
  y = x + 5
} catch (exception e) {

} catch (char* e) {

}
cout << "End of program";
 */

#include <iostream>
#include <cassert>

double divide(int a, int b);

int main() {
  try {
    divide(5, 0);
    std::cout << "Division finished" << std::endl;
  }
  catch (char* e) {
    std::cout << "throw an char* type error" << std::endl;
  }
  catch (int e) {
    std::cout << "throw an int type error" << std::endl;
    std::cout << "Can't divide 0" << std::endl;
    std::cout << e << std::endl;
  }

  std::cout << "End of the program" << std::endl;
  return 0;
}

double divide(int a, int b) {
  if (b == 0) {
    throw -12345;
  }
  double x = a / b;
  return x;
}