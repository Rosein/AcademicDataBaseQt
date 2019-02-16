#pragma once
#include "Person.h"
class Student :
	public Person
{
    int index;
public:
    char getType() const { return 'S'; }
    void setSalary(unsigned int){}
    int getIndex() const { return index; }
    void print(std::ostream& os);
    bool operator==(const Student&);
    Student& operator=(const Student&);
    Student() = default;
    Student(const std::string & name,
            const std::string & surname,
            const std::string & address,
            Sex sex,
            Pesel pesel, int index );
    Student(const Student & c);
    Student(Student&&) = default;
    ~Student();
};

