#pragma once
#include "Pesel.h"
#include <string>
#include <iostream>
enum class Sex { male, female };
const int NO_INDEX = 0;
const int NO_SALARY = 0;

class Person
{
protected:
    std::string name;
    std::string surname;
    std::string address;
    Sex sex;
    Pesel pesel;

public:

    Person() = default;
    Person( const std::string & name,
            const std::string & surname,
            const std::string & address,
                  Sex sex,
                  Pesel pesel);
    Person(const Person &);

    virtual ~Person() {}
    virtual void setSalary( unsigned int salary ){}
    void setAddress(const std::string & new_address) { address = new_address; }
    virtual int getIndex() const { return NO_INDEX; }
    virtual unsigned int getSalary() const { return NO_SALARY; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    std::string getAddress() const { return address; }
    Sex getSex() const { return sex; }
    Pesel getPesel() const { return pesel; }
    bool isSexDigitValid();
    bool isPeselValid();
    virtual void print(std::ostream& os);
    virtual char getType() const { return 'P'; }
    friend  bool operator==(const Person&, const Person&);
};

