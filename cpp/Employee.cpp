#pragma once
#include "headers/Employee.h"

Employee::Employee( const std::string & name,
                                const std::string & surname,
                                const std::string & address,
				                Sex sex,
                                Pesel pesel,
                                unsigned int salary)
    : Person(name,surname,address,sex,pesel), salary(salary)
{}
void Employee::print(std::ostream& os)
{
    const int WIDTH = 12;
    const std::string EMPTY_FIELD = " ";

    os  << std::left
        << std::setw(WIDTH/2) << this->getType()
        << std::setw(WIDTH)   << name
        << std::setw(WIDTH)   << surname
        << std::setw(WIDTH*2) << address
        << std::setw(WIDTH)   << ( (sex == Sex::female) ? "female" : "male" )
        << std::setw(WIDTH)   << pesel
        << std::setw(WIDTH)   << EMPTY_FIELD    // index
        << std::setw(WIDTH)   << salary;
}
char Employee::getType() const
{
    return 'E';
}
unsigned int Employee::getSalary() const
{
    return salary;
}
void Employee::setSalary(unsigned int new_salary)
{
    salary = new_salary;
}
Employee::~Employee()
{}
