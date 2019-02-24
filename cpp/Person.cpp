#pragma once
#include "headers/Person.h"

bool Person::isSexDigitValid()
{
    if( sex == Sex::male )
        if( getPesel().giveSexDigit() % 2 == 1 )
            return true;
    if( sex == Sex::female )
        if( getPesel().giveSexDigit() % 2 == 0 )
            return true;
    return false;
}
bool Person::isPeselValid()
{
    return pesel.isControlDigitValid() && isSexDigitValid();
}
bool operator==(Person& first , Person& second)
{
    return first.getPesel() == second.getPesel();
}
void Person::setAddress(const std::string & new_address)
{
    address = new_address;
}
std::string Person::getSurname() const
{
    return surname;
}
Pesel Person::getPesel() const
{
    return pesel;
}
char Person::getType() const
{
    return 'P';
}

int Person::getIndex() const
{
    const int NO_INDEX = 0;
    return NO_INDEX;
}
unsigned int Person::getSalary() const
{
    const unsigned int NO_SALARY = 0;
    return NO_SALARY;
}
void Person::print(std::ostream& os)
{
    const int WIDTH = 12;
    os  << std::left
        << std::setw(WIDTH)   << name
        << std::setw(WIDTH)   << surname
        << std::setw(WIDTH*2) << address
        << std::setw(WIDTH)   << ( (sex == Sex::female) ? "female" : "male" )
        << std::setw(WIDTH)   << pesel;
}
Person::Person( const std::string & name,
                const std::string & surname,
                const std::string & address,
                Sex sex,
                Pesel pesel)
    :name(name),
     surname(surname),
     address(address),
     sex(sex),
     pesel(pesel) {}
