#pragma once
#include "headers/RandomPerson.h"

Sex RandomPerson::getRandomSex()
{
    return ( getRandomInt( 0, 1 ) ? Sex::male : Sex::female );
}
std::string RandomPerson::getRandomSurname()
{
    std::vector<std::string> surname = {"Turtle", "Bonaparte", "McDonald", "Diesel", "Dalisbog", "Acomitam" };
    return surname[ getRandomInt(0, surname.size() - 1 ) ];
}
std::string RandomPerson::getRandomName( Sex sex )
{
    std::vector<std::string> f_name = {"Ann", "Daria", "Margaret", "Elisabeth", "Amelia" };
    std::vector<std::string> m_name = {"Jack", "Deryl", "John", "Peter", "Scot", "Shrek" };
    std::string name_;
    if( sex == Sex::male )
    {
        name_ = m_name [ getRandomInt(0, m_name.size() - 1 ) ];
    } else
    {
        name_ = f_name [ getRandomInt(0, f_name.size() - 1 ) ];
    }
    return name_;
}
std::string RandomPerson::getRandomAddress()
{
     std::vector<std::string> address = {"Czekoladowa", "Truskawkowa", "Internetowa", "Bezprzewodowa", "Tesli", "McConora"};
     std::string address_ = address [ getRandomInt(0, address.size() - 1 ) ];
     address_ += " " + std::to_string( getRandomInt(0, 30 ) );
     return address_;
}
std::string RandomPerson::getRandomPesel( Sex sex )
{

    std::string pesel_ = std::to_string( getRandomInt( 100'000'000, 999'999'999 ) );
    int base = 2 * getRandomInt( 0, 4 );
    if( sex == Sex::male )
        ++base;
    pesel_ += std::to_string( base );
    pesel_ += std::to_string( getRandomInt( 0, 9 ) );
    return pesel_;
}
int RandomPerson::getRandomInt( unsigned int from, unsigned int to )
{   
    static std::random_device rd;
    static std::mt19937 gen{ rd() };
    std::uniform_int_distribution<> random_index( from, to );
    int random_number = random_index( gen );
    return random_number;
}
PersonPtr RandomPerson::getRandomStudent()
{
    Sex sex_ = getRandomSex();
    std::string surname_ = getRandomSurname();
    std::string name_ = getRandomName( sex_ );
    std::string address_ = getRandomAddress();
    std::string pesel_ = getRandomPesel( sex_ );

    int index_ = getRandomInt( 10000, 99999 );
    PersonPtr random_student = std::make_shared<Student>( name_, surname_, address_, sex_, pesel_, index_ );
    return  random_student;
}
PersonPtr RandomPerson::getRandomEmployee()
{
    Sex sex_ = getRandomSex();
    std::string surname_ = getRandomSurname();
    std::string name_ = getRandomName( sex_ );
    std::string address_ = getRandomAddress();
    std::string pesel_ = getRandomPesel( sex_ );

    int salary_ = getRandomInt( 1000, 9999 );
    PersonPtr random_employee = std::make_shared<Employee>( name_, surname_, address_, sex_, pesel_, salary_ );
    return  random_employee;
}

PersonPtr RandomPerson::generate()
{
    return ( getRandomInt(0, 1) ? getRandomStudent() : getRandomEmployee() );
}
