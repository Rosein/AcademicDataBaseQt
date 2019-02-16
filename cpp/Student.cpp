#include "headers/Student.h"
#include <iomanip>

bool Student::operator==(const Student& other)
{
	   return getIndex() == other.getIndex();
}

void Student::print(std::ostream& os)
{
    const int WIDTH = 12;
    const std::string EMPTY_FIELD = " ";

    os  << std::left
        << std::setw(WIDTH/2) << getType()
        << std::setw(WIDTH)   << name
        << std::setw(WIDTH)   << surname
        << std::setw(WIDTH*2) << address
        << std::setw(WIDTH)   << ( (sex == Sex::female) ? "female" : "male" )
        << std::setw(WIDTH)   << pesel
        << std::setw(WIDTH)   << index
        << std::setw(WIDTH)   << EMPTY_FIELD;
}

Student& Student::operator=( const Student & c)
{
    name = c.getName();
    surname = c.getSurname();
    address = c.getAddress();
    sex = c.getSex();
    index = c.getIndex();
    pesel = c.getPesel();
    return *this;
}
Student::Student(const std::string & name,
                 const std::string & surname,
                 const std::string & address,
                 Sex sex,
                 Pesel pesel, 
                 int index)
	: Person(name, surname, address, sex, pesel),
	  index(index)
{}
Student::Student(const Student & c) : Person(c),
									  index(c.getIndex())
{}
Student::~Student()
{}
