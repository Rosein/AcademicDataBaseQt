#pragma once
#include "Pesel.h"
#include <string>
#include <iostream>
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
    Person() = delete;
    Person( const std::string & name,
            const std::string & surname,
            const std::string & address,
                  Sex sex,
                  Pesel pesel);
    Person(const Person &);
    friend std::ostream& operator<<(std::ostream& os, const Person & p);
    virtual ~Person() {}
    void setAddress(const std::string & new_address) { address = new_address; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    std::string getAddress() const { return address; }
    Sex getSex() const { return sex; }
    Pesel getPesel() const { return pesel; }
    friend  bool operator==(const Person&, const Person&);

};

