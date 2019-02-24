#pragma once
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <memory>
#include <random>

#include"Student.h"
#include"Employee.h"
#include"RandomPerson.h"

using PersonPtr = std::shared_ptr<Person>;
using People = std::vector<PersonPtr>;
using StudentPtr = std::shared_ptr<Student>;
using Students = std::vector<Student>;

class Database
{
    People allPeople;
public:
    void add(PersonPtr &&);
    void show();
    void sortByIndex();
    void sortByPesel();
    void sortBySurname();
    void sortBySalary();
    void removeByIndex(int);
    void removeByPesel(const std::string &);
    void setAddress(const std::string & pesel, const std::string & address);
    void setSalary(const std::string & pesel, unsigned int salary);
    People findBySurname(const std::string & surname);
    PersonPtr findByPesel(const std::string & nr);
    void generate(int);
    void save(const std::string &);
    void load(const std::string &);
    friend std::ostream& operator<<(std::ostream&, const Database &);
};

