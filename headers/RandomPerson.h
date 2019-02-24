#pragma once
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include <memory>
#include <random>

using PersonPtr = std::shared_ptr<Person>;

class RandomPerson
{
private:
    Sex getRandomSex();
    std::string getRandomName( Sex );
    std::string getRandomSurname();
    std::string getRandomAddress();
    std::string getRandomPesel( Sex );
    int getRandomInt( unsigned int, unsigned int );
    PersonPtr getRandomStudent();
    PersonPtr getRandomEmployee();
public:
    PersonPtr generate();
};
