#include "headers/Person.h"
#include <iomanip>

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
bool operator==(Person& first , Person& second)
{
    return first.getPesel() == second.getPesel();
}
std::ostream& operator<<(std::ostream& os, const Person & p)
{
    const int WIDTH = 12;
    os  << std::left
        << std::setw(WIDTH)   << p.name
        << std::setw(WIDTH)   << p.surname
        << std::setw(WIDTH*2) << p.address
        << std::setw(WIDTH)   << ( (p.sex == Sex::female) ? "female" : "male" )
        << std::setw(WIDTH)   << p.pesel;
    return os;
}

Person::Person(const Person & c)
    :name( c.name ),
     surname( c.surname ),
     address( c.address ),
     sex( c.sex ),
     pesel( c.pesel ) {}

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
