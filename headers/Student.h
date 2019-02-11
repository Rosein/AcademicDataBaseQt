#pragma once
#include "Person.h"
class Student :
	public Person
{
    int index;
public:
    int getIndex() const { return index; }
    bool operator==(const Student&);
    Student& operator=(const Student&);
    friend std::ostream& operator<<(std::ostream& os, const Student & c);
    Student(const std::string & name,
            const std::string & surname,
            const std::string & address,
            Sex sex,
            Pesel pesel, int index );
    Student(const Student & c);
    Student(Student&&) = default;
    ~Student();

};

