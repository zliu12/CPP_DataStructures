#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <string>

bool isPalindrome(std::string word);

int main() {
  std::string words[] = {"Radar", "ta,cOCat", "dr ums", "A man, a PLAN, a canal, panama"};
  for (auto word : words) {
    if (isPalindrome(word)) {
      std::cout << word << " is a palindrome";
    } else {
      std::cout << word << " is not a palindrome";
    }
    std::cout << std::endl;
  }

  return 0;
}

bool isPalindrome(std::string word) {
  Queue q;
  Stack s;
  for (auto character : word) {
    if (isalpha(character)) {
      q.push(tolower(character));
      s.push(tolower(character));
    }
  }
  while (!q.empty() && !s.empty()) {
    if (q.front() != s.top()) {
      return false;
    }
    q.pop();
    s.pop();
  }
  return true;
}