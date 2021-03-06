/**
 * Friend Function
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* What is friend function
1. A function can access private member variables and member functions
2. Friend functions are not member funcionts, not part of the class
3. Class must declare the function as a friend
4. Using the keyword friend
5. Difference between friend function operator and member function operator:
  a. Member function operator usually takes one parameter
  b. Member function operator usually makes changes to the object calling the
     function (object on the left)
6. Member function example:
  a. Assiment op (=)
  b. Plus equal op (+=)
  c. Minus equal op (-=)
  d. Multiply equal op (*=)
  e. Decrement/increment (--/++)
  f. Bracket op([])
 */

#include <string>

class Card {
 private:
  std::string suit;
  int rank;

 public:
  Card(std::string s1, int num) : suit(s1), rank(num) {};
  friend  int operator+(const Card &LHS, const Card &RHS);
  Card &operator[](unsigned int index);
};

int operator+(const Card &LHS, const Card &RHS) {

}

Card& Card::operator[](unsigned int index) {
  Card cards("Diamond", 6);
  return cards[index];
}

int main() {
  Card card1("Heart", 2);
  Card card2("Heart", 5);

  // int total = operation+(card1, card2);
  int total = card1 + card2;
}