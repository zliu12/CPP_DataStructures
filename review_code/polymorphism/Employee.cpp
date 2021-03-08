#include "Employee.h"

Employee::Employee() : Person() {

}

Employee::Employee(std::string firstName, std::string lastName, int employeeNumber)
: Person(firstName, lastName) {
  this->employeeNumber = employeeNumber;
}

int Employee::getEmployeeNumber() const {

}

void Employee::setEmployeeNumber(int employeeNumber) {

}