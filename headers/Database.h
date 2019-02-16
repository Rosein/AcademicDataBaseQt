#pragma once
#include <vector>
#include <memory>
#include <random>
#include"Student.h"
#include"Employee.h"

using PersonPtr = std::shared_ptr<Person>;
using People = std::vector<PersonPtr>;
using StudentPtr = std::shared_ptr<Student>;
using Students = std::vector<Student>;

class Database
{
    People allPeople;

    Sex getRandomSex();
    std::string getRandomName( Sex );
    std::string getRandomSurname();
    std::string getRandomAddress();
    std::string getRandomPesel( Sex );
    int getRandomInt( unsigned int, unsigned int );
    PersonPtr getRandomStudent();
    PersonPtr getRandomEmployee();

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
    Database() = default;
    ~Database() = default;
    //bool isValid(Pesel);



};

