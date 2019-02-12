#pragma once
#include <vector>
#include <memory>

#include"Student.h"
#include"Employee.h"

//using PersonPtr = std::unique_ptr<Person>;
using StudentPtr = std::shared_ptr<Student>;

class Database
{
    std::vector<Student> allPeople;
public:

    void add(Student && student);
    void show();
    void sortByIndex();
    void sortByPesel();
    void sortBySurname();
    void removeByIndex(int);
    void removeByPesel(const std::string &);
    void setAddressIndicatedByPesel(const std::string &, const std::string &);
    std::vector<Student> findBySurname(const std::string & surname);
    StudentPtr findByPesel(const std::string & nr);
    void generate(int);
    void save(const std::string &);

    friend std::ostream& operator<<(std::ostream&, Database);
    std::istream& operator>>(std::istream& os);

    /*void save();
    void load();
	
    void modifySalary(Employee&, int);
    void modifyAddress(Person&, std::string);
    bool isValid(Pesel);*/

    Database();
    ~Database();
};

