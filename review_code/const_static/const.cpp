/**
 * Const
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* Const
1. A const var cannot change
2. Declare and initialize right away
3. Things that never change like Pi
 */
#include <string>

class MyClass {
 public:
  // const here means returned value cannot be changed
  const std::string f();
  // const here means member var inside the fuc not gonna change, usually used
  // for getters
  std::string g() const;

 private:
  int x;
};

int main() {
  MyClass m;
  // Error here
  // m.f().at(i) = 'C';
}
