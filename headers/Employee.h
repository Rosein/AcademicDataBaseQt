#pragma once
#include "Person.h"
class Employee :
	public Person
{
    unsigned int salary;
public:
    char getType() const;
    unsigned int getSalary() const;
    void setSalary(unsigned int new_salary);
    void print(std::ostream& os);
    Employee(const std::string & name,
                      const std::string & surname,
                      const std::string & address,
			          Sex sex,
                      Pesel pesel,
                      unsigned int salary);
    ~Employee();
};
