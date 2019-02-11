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
    Student(const char name[],
            const char surname[],
            const char address[],
            Sex sex,
            Pesel pesel, int index );
    Student(const Student & c);
    Student(Student&&) = default;
    ~Student();

};

