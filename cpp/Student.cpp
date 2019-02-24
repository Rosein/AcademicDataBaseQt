#include "headers/Student.h"

bool Student::operator==(const Student& other)
{
	   return getIndex() == other.getIndex();
}
char Student::getType() const
{
    return 'S';
}
int Student::getIndex() const
{
    return index;
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

Student::Student(const std::string & name,
                 const std::string & surname,
                 const std::string & address,
                 Sex sex,
                 Pesel pesel, 
                 int index)
	: Person(name, surname, address, sex, pesel),
	  index(index)
{}
Student::~Student()
{}
