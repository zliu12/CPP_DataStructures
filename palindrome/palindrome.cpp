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
  bool check_palindrome(string &s) const {
    /* Using iterator */
  //   string::iterator it_begin = s.begin();
  //   string::iterator it_end = s.end() - 1;
  //   while (it_begin != it_end && it_begin < it_end) {
  //     if (it_begin != it_end) {
  //       return false;
  //     } else {
  //       it_begin++;
  //       it_end--;
  //     }
  //   }
  //   return true;
  // }

    // Using pointer
    // when the beginning character is not equal to the ending character and 
    // they are not adjcent
    unsigned s_size = s.size();
    const char *begin = &s[0];
    const char *end = &s[s_size - 1];
    // The loop goes as long as the pointed to address of begin and end are not
    // equal, and the address pointed to by begin is "before" the address 
    // pointed to by end
    while (begin != end && begin < end) {
      if (*begin != *end) {
        return false;
      } else {
        cout << *begin << *end << endl;
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