
#include "Person.h"
#include <string>

class Employee : public Person {
 private:
  int employeeNumber;
  std::string lastName, firstName;

 public:
  Employee();
  Employee(std::string firstName, std::string lastName, int employeeNumber);
  int getEmployeeNumber() const;
  void setEmployeeNumber(int employeeNumber);
};