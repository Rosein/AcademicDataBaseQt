#include "headers/Person.h"
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Person & p)
{
    const int WIDTH = 12;
    os  << std::left << std::setw(WIDTH) << p.name
        << std::setw(WIDTH) << p.surname
        << std::setw(2*WIDTH) << p.address;
    if (p.sex == Sex::female)
        os << std::setw(WIDTH) << "female";
    else
        os << std::setw(WIDTH) << "male";
    os << std::setw(WIDTH) << p.pesel;
    return os;
}
bool operator==(Person& first , Person& second)
{
	return first.getPesel() == second.getPesel();
}
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
    bool isValid = pesel.isControlDigitValid();
    isValid = isValid && isSexDigitValid();
    return isValid;
}
Person::Person(const Person & c)
    : name( c.getName()),
         surname( c.getSurname() ),
         address( c.getAddress() ),
         sex( c.getSex() ),
         pesel( c.getPesel() ) {}

Person::Person( const std::string & name,
                const std::string & surname,
                const std::string & address,
                Sex sex,
                Pesel pesel)
    : name(name),
         surname(surname),
         address(address),
	     sex(sex),
	     pesel(pesel) {}
