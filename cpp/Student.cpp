#include "headers/Student.h"
#include <iomanip>

bool Student::operator==(const Student& other)
{
	   return getIndex() == other.getIndex();
}
std::ostream& operator<<(std::ostream& os, const Student & s)
{
    const int WIDTH = 12;
    os << std::left << std::setw(WIDTH) << s.name
       << std::setw(WIDTH) << s.surname
       << std::setw(2 * WIDTH) << s.address;
    if (s.sex == Sex::female)
        os << std::setw(WIDTH) << "female";
    else
        os << std::setw(WIDTH) << "male";
    os << std::setw(WIDTH) << s.pesel;
    os << std::setw(WIDTH) << s.index;
    return os;
}
std::istream& operator>>(std::istream& is, Student & s)
{
    std::string broker;
    is >> broker;
    s.name = broker;
    is >> broker;
    s.surname = broker;
    is >> broker;
    s.address = broker;
    is >> broker;
    s.address += " " + broker;
    is >> broker;
    s.sex = ( broker[0] == 'f' ) ? Sex::female : Sex::male;
    is >> broker;
    s.pesel = Pesel(broker);
    int index;
    is >> index;
    s.index = index;
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
