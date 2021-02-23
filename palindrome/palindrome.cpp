/**
 * Assignment - Palindrome.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class IfPalindrome {
 private:
  string _s;

 public:
  /*
  Function sets the value of the private member variable _s 
  Param: a string variable
  Return: a string
   */
  string set_string(string s) {
    return _s = s;
  }

  /* 
  Function reads the string from users
  Param: a string variable to store the input string
  Return: none
   */
  string read_string(string s) {
    cout << "Enter a string: ";
    cin >> s;
    return set_string(s);
  }

  /* 
  Function check if the input string is a palindrome
  Param: a string variable stores the input string from users
  Return: true if the input string is a palindrome, false otherwise
   */
  bool check_palindrome(const string &s) {
    unsigned s_size = s.size();
    const char *begin = &s[0];
    const char *end = &s[s_size - 1];
    while (begin != end && begin != (end + 1)) {
      if (*begin != *end) {
        return false;
      } else {
        begin++;
        end--;
      }
    }
    return true;
  }
};

int main() {
  IfPalindrome str;
  string str_input;
  bool result;
  str_input = str.read_string(str_input);
  result = str.check_palindrome(str_input);
  cout << str_input << " is a palindrome: " << result << endl;
  return 0;
}