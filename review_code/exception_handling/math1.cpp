#include <iostream>
#include <cassert>
#include "math.h"

int main() {
  try {
    std::cout << Math::divide(5, 0) << std::endl;
    std::cout << Math::sqrt(-4) << std::endl;
  }
  catch (DivideByZeroExcpetion e) {
    std::cout << e.what() << std::endl;
    std::cout << Math::divide(5, 1) << std::endl;
  }
  catch (NegativeNumberExcpetion e) {
    std::cout << e.what() << std::endl;
    std::cout << Math::sqrt(4) << std::endl;
  }

  std::cout << "End of the program" << std::endl;
  return 0;
}

// double divide(int a, int b) {
//   if (b == 0) {
//     throw -12345;
//   }
//   double x = a / b;
//   return x;
// }