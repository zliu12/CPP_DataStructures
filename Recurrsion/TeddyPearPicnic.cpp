#include <iostream>

bool bears(int n);

int main() {
  std::cout << "\n" << bears(120) << std::endl;         // 0
  std::cout << "\n" << bears(250) << std::endl;         // 1
  std::cout << "\n" << bears(42) << std::endl;          // 1
  std::cout << "\n" << bears(0) << std::endl;           // 0
  std::cout << "\n" << bears(88) << std::endl;          // 0

  return 0;
}

bool bears(int n) {
  // Create a temp to hold value of n before n is modified
  int n_temp;

  // If n is less than 42, return false
  if (n < 42) {
    return false;
  }
  else {
    // Base case: n = 42
    if (n == 42) {
      return true;
    }

    // Give back half amount of Teddy if the number of Teddy is even
    if (n % 2 == 0) {
      n_temp = n / 2;
      // std::cout << n << ", " << n_temp << ", n % 2" << std::endl;
      if (bears(n_temp)) {
        return true;
      }
    }

    // If the number of Teddy is divisible by 3 or 4, multiply the last two
    // digits of n and give back this many bears.
    if (n % 3 == 0 || n % 4 == 0) {
      n_temp = n - (n % 100 / 10) * (n % 10);
      // std::cout << n << ", " << n_temp << ", n % 3 || n % 4" << std::endl;
      // Check if the product of the last two digits is 0
      // If the product is 0, it will incur the repeat of the whole procedure,
      // in which causing the infinite recurrsion
      if (n_temp != n) {
        if (bears(n_temp)) {
          return true;
        }
      }
    }

    // If the number of Ted is divisible by 5, the amount of Ted that is given
    // back is the number of Ted minus 42
    if (n % 5 == 0) {
      n_temp = n - 42;
      // std::cout << n << ", " << n_temp << ", n % 5" << std::endl;
      if (bears(n_temp)) {
        return true;
      }
    }
  }
  
  return false;
}