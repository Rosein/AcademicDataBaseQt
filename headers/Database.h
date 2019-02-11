#pragma once
#include <vector>
#include <memory>

#include"Student.h"
#include"Employee.h"

//using StudentPtr = std::unique_ptr<Student>;

class Database
{
    std::vector<Student> allPeople;
public:
    //	std::ostream& operator<<(std::ostream& os);
    void show();
    void sort();
    void remove(int);
    void add(Student && student);
    /*auto find(std::string surname);
    auto find(Pesel sought);
    void generate();
    void save();
    void load();
	
    void modifySalary(Employee&, int);
    void modifyAddress(Person&, std::string);
    bool isValid(Pesel);*/

    Database();
    ~Database();
};

