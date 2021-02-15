/**
 * Programming Project.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* Find Your Chinese Zodiac - The Twelve Animal Guardians */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

const int YEAR_LOWER_BOUND = 1900;
const int YEAR_UPPER_BOUND = 2021;
const int INPUT_LENGTH = 4;

// Check if input characters are digits
bool checkDigit(const std::string &s) {
  for (unsigned i = 0; i < s.size(); ++i) {
    if (!isdigit(s[i])) {
      std::cout << "Invalid input: Non-numerical character exists.\n"
                << std::endl;
      return false;
    }
  }
  return true;
}

// Check input size
bool checkLength(const std::string &s) {
  if (s.size() != INPUT_LENGTH) {
    std::cout << "Invalid input: Wrong number of characters entered.\n"
              << std::endl;
    return false;
  }
  return true;
}

// Check input time frame
bool checkTimeFrame(const std::string &s) {
  if (0 <= std::stoi(s) && std::stoi(s) < YEAR_LOWER_BOUND) {
    std::cout << "Invalid input: Out of time frame. The Man From Earth?\n"
              << std::endl;
    return false;
  } else if (std::stoi(s) > YEAR_UPPER_BOUND) {
    std::cout << "Invalid input: Out of time frame. Back To The Future!\n"
              << std::endl;
    return false;
  }
  return true;
}

// Validate input
bool validate_year_of_birth(const std::string &s) {
  if (checkDigit(s) && checkLength(s) && checkTimeFrame(s)) {
    return true;
  }
  return false;
}

// Input year of birth
std::string input_year_of_birth() {
  std::string year_str;
  std::cout << "Welcome to Find Your Chinese Zodiac - The Twelve Animal "
            << "Guardians" << std::endl << std::endl;
  std::cout << "Please enter your year of birth (YYYY): ";
  std::getline(std::cin, year_str);
  std::cout << std::endl;
  return year_str;
}

// Find your animal guardian
void animal_guardian(const std::string &s, const std::vector<std::string> &v) {
  int n = std::stoi(s);
  int result = n % v.size();
  switch (result) {
    case 0:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 1:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 2:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 3:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 4:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 5:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 6:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 7:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 8:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 9: 
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;     
    case 10: 
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
    case 11:
      std::cout << "Your animal guardian is: "  << v[result] << std::endl;
      break;
  }
}

// find the next guardian year
void next_guardian_year (const std::string &s) {
  int n = stoi(s);
  time_t t = time(NULL);
  tm *tptr = localtime(&t);
  while (n < tptr->tm_year + 1900) {
    n += 12;
  }

  if (n == (tptr->tm_year + 1900)) {
    std::cout << "This year is your guardian year!\n";
    std::cout << "The year of " << n + 12 
              << " will be your next guardian year." << std::endl;
  } else {
    std::cout << "The year of " << n << " will be your next guardian year."
              << std::endl;
  }
  std::cout << "Remember wearing a red will bring you good luck!" << std::endl;
}

int main() {
  // Create a vector to hold 12 zodiac
  std::vector<std::string> zodiac_vec = {"Monkey", "Rooster", "Dog", "Pig", "Rat", 
    "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat"};
  
  // Take input and validate
  std::string year_of_birth_str;
  do {
    year_of_birth_str = input_year_of_birth();
  } while (!validate_year_of_birth(year_of_birth_str));

  // Output animal guardian result
  animal_guardian(year_of_birth_str, zodiac_vec);

  // Output the next animal guardian year
  next_guardian_year(year_of_birth_str);

  return 0;
}