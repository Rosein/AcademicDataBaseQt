#include "headers/Database.h"
#include <algorithm>
#include <random>

void Database::add(Student && student)
{
	   allPeople.emplace_back(student);
}
void Database::show()
{
    for (auto & it : allPeople)
	       std::cout << it << std::endl;
    std::cout << std::endl;
}
void Database::sortByIndex()
{
    class ComparerIndex {
    public:
	       bool operator()(const Student & a, const Student & b) const
	       {
		          return a.getIndex() <= b.getIndex();
	       }
    };
    std::sort(allPeople.begin(),allPeople.end(), ComparerIndex());
}
void Database::sortByPesel()
{
    class ComparerPesel {
    public:
           bool operator()(const Student & a, const Student & b) const
           {
                  return a.getPesel() <= b.getPesel();
           }
    };
    std::sort(allPeople.begin(),allPeople.end(), ComparerPesel());
}
void Database::sortBySurname()
{
    class ComparerSurname {
    public:
           bool operator()(const Student & a, const Student & b) const
           {
                  return a.getSurname() <= b.getSurname();
           }
    };
    std::sort(allPeople.begin(),allPeople.end(), ComparerSurname());
}
void Database::removeByIndex(int nr_index)
{
    int i;
    for( i = 0; i < allPeople.size(); ++i )
        if (allPeople[i].getIndex() == nr_index)
        {
            allPeople.erase(allPeople.begin() + i);
            break;
        }
}
void Database::removeByPesel(const std::string & pesel)
{
    auto sought_pesel = find_if(allPeople.begin(),allPeople.end(), [&pesel](const Student & student)
    {
        return student.getPesel() == pesel;
    });
    if (sought_pesel != allPeople.end() )
       allPeople.erase( sought_pesel );
}
std::vector<Student> Database::findBySurname(const std::string & surname)
{
    std::vector<Student> founded;
    copy_if(allPeople.begin(), allPeople.end(), std::back_inserter(founded),
            [&surname](const Student & candi)
    {
        return candi.getSurname() == surname;
    });
    return founded;
}
StudentPtr Database::findByPesel(const std::string & nr)
{
    auto it = find_if(allPeople.begin(), allPeople.end(),
            [&nr](const Student & candi)
    {
        return candi.getPesel() == nr;
    });
    if ( it == allPeople.end() )
        return nullptr;
    StudentPtr founded = std::make_shared<Student>(*it);
    return founded;
}
void Database::generate( int n = 40 )
{
    std::vector<std::string> f_name = {"Ann", "Daria", "Margaret", "Elisabeth", "Amelia" };
    std::vector<std::string> m_name = {"Jack", "Deryl", "John", "Peter", "Scot", "Shrek" };
    std::vector<std::string> surname = {"Turtle", "Bonaparte", "McDonald", "Diesel", "Dalisbog", "Acomitam" };
    std::vector<std::string> address = {"Czekoladowa", "Truskawkowa", "Internetowa", "Bezprzewodowa", "Tesli", "McConora"};
    std::random_device rd;
    std::mt19937 gen( rd() );

    for( int i = 0; i < 40; ++i )
    {
        std::uniform_int_distribution<> random_sex(0, 1);
        Sex sex_ = ( random_sex( gen ) == 0 ) ? Sex::male : Sex::female;
        std::uniform_int_distribution<> random_surname(0, surname.size() - 1 );
        std::string surname_ = surname[ random_surname( gen ) ];

        std::string name_;
        if( sex_ == Sex::male )
        {
            std::uniform_int_distribution<> random_m_name(0, m_name.size() - 1 );
            name_ = m_name [ random_m_name( gen ) ];
        } else
        {
            std::uniform_int_distribution<> random_f_name(0, f_name.size() - 1 );
            name_ = f_name [ random_f_name( gen ) ];
        }
        std::uniform_int_distribution<> random_address(0, address.size() - 1 );
        std::string address_ = address [ random_address( gen ) ];
        address_ += " " + std::to_string( random_address( gen ) + 1 );
        std::uniform_int_distribution<> random_pesel(100'000'000, 999'999'999 );
        std::string pesel_ = std::to_string( random_pesel( gen ) );
        std::uniform_int_distribution<> random_sex_digit(0,4);
        int base = 2 * random_sex_digit( gen );
        if( sex_ == Sex::male )
            ++base;
        pesel_ += std::to_string( base );
        std::uniform_int_distribution<> random_control_digit(0,9);
        pesel_ += std::to_string( random_control_digit( gen ));
        std::uniform_int_distribution<> random_index( 0,10000 );
        int index_ = random_index( gen );
        Student random_student (name_, surname_, address_, sex_, pesel_, index_);
        allPeople.emplace_back( random_student );
    }
}
Database::Database()
{
}
Database::~Database()
{
}
