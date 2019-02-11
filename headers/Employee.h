#pragma once
#include "Person.h"
class Employee :
	public Person
{
    unsigned int salary;
public:
    int getSalary()const { return salary; }
    void setSalary(int new_salary) { salary = new_salary; }
    Employee(const char name[],
			          const char surname[],
			          const char address[],
			          Sex sex,
			          Pesel pesel);
    ~Employee();
};
