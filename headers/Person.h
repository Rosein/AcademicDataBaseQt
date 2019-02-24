#pragma once
#include "Pesel.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>
enum class Sex { male, female };

class Person
{
protected:
    std::string name;
    std::string surname;
    std::string address;
    Sex sex;
    Pesel pesel;

public:
    Person( const std::string & name,
            const std::string & surname,
            const std::string & address,
                  Sex sex,
                  Pesel pesel);

    virtual ~Person() {}
    virtual void setSalary( unsigned int ){}
    void setAddress(const std::string & new_address);
    virtual void print(std::ostream& os);
    virtual int getIndex() const;
    virtual unsigned int getSalary() const;
    virtual char getType() const;
    std::string getSurname() const;
    Pesel getPesel() const;
    bool isSexDigitValid();
    bool isPeselValid();
    friend  bool operator==(const Person&, const Person&);
};

