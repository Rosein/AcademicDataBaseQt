#include "headers/Database.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <iomanip>

void Database::add( PersonPtr && person )
{
       allPeople.emplace_back(person);
}
void Database::show()
{
    std::cout << *this;
}
void Database::sortByIndex()
{
    class ComparerIndex {
    public:
           bool operator()(const PersonPtr & a, const PersonPtr & b) const
	       {
                  return a->getIndex() <= b->getIndex();
	       }
    };
    std::sort(allPeople.begin(),allPeople.end(), ComparerIndex());
}
void Database::sortByPesel()
{
    class ComparerPesel {
    public:
           bool operator()( const PersonPtr & a, const PersonPtr & b ) const
           {
                  return a->getPesel() <= b->getPesel();
           }
    };
    std::sort( allPeople.begin(), allPeople.end(), ComparerPesel() );
}
void Database::sortBySurname()
{
    class ComparerSurname {
    public:
           bool operator()( const PersonPtr & a, const PersonPtr & b ) const
           {
                  return a->getSurname() <= b->getSurname();
           }
    };
    std::sort(allPeople.begin(),allPeople.end(), ComparerSurname());
}
void Database::sortBySalary()
{
    class ComparerIndex {
    public:
           bool operator()(const PersonPtr & a, const PersonPtr & b) const
           {
                  return a->getSalary() >= b->getSalary();
           }
    };
    std::sort(allPeople.begin(),allPeople.end(), ComparerIndex());
}
void Database::removeByIndex( int nr_index )
{
    const int NO_INDEX = 0;
    if( nr_index == NO_INDEX ) return;
    auto sought_student = std::find_if( allPeople.begin(), allPeople.end(),
        [ nr_index ]( const PersonPtr & p ){
            return p->getIndex() == nr_index;
    });
    if ( sought_student != allPeople.end() )
            allPeople.erase( sought_student );
}
void Database::removeByPesel( const std::string & pesel )
{
    auto sought_pesel = find_if(allPeople.begin(),allPeople.end(), [&pesel](const PersonPtr & person)
    {
        return person->getPesel() == pesel;
    });
    if (sought_pesel != allPeople.end() )
       allPeople.erase( sought_pesel );
}
void Database::setAddress( const std::string & pesel, const std::string & new_address )
{
    auto sought_student = findByPesel( pesel );
    if( sought_student != nullptr )
        sought_student->setAddress( new_address );
}
void Database::setSalary( const std::string & pesel, unsigned int salary )
{
    auto sought_employee = findByPesel( pesel );
    if( sought_employee != nullptr && sought_employee->getType() == 'E' )
        sought_employee->setSalary( salary );
}
People Database::findBySurname( const std::string & surname )
{
    People founded;
    copy_if(allPeople.begin(), allPeople.end(), std::back_inserter(founded),
            [ &surname ](const PersonPtr & candi)
    {
        return candi->getSurname() == surname;
    });
    return founded;
}
PersonPtr Database::findByPesel( const std::string & nr )
{
    auto it = find_if(allPeople.begin(), allPeople.end(),
            [ &nr ](const PersonPtr & candi)
    {
        return candi->getPesel() == nr;
    });
    if ( it == allPeople.end() )
        return nullptr;
    return *it;
}
Sex Database::getRandomSex()
{
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_int_distribution<> random_sex( 0, 1 );
    return ( ( random_sex( gen ) == 0 ) ? Sex::male : Sex::female );
}
std::string Database::getRandomSurname()
{
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::vector<std::string> surname = {"Turtle", "Bonaparte", "McDonald", "Diesel", "Dalisbog", "Acomitam" };
    std::uniform_int_distribution<> random_surname(0, surname.size() - 1 );
    return surname[ random_surname( gen ) ];
}
std::string Database::getRandomName( Sex sex )
{
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::vector<std::string> f_name = {"Ann", "Daria", "Margaret", "Elisabeth", "Amelia" };
    std::vector<std::string> m_name = {"Jack", "Deryl", "John", "Peter", "Scot", "Shrek" };
    std::string name_;
    if( sex == Sex::male )
    {
        std::uniform_int_distribution<> random_m_name(0, m_name.size() - 1 );
        name_ = m_name [ random_m_name( gen ) ];
    } else
    {
        std::uniform_int_distribution<> random_f_name(0, f_name.size() - 1 );
        name_ = f_name [ random_f_name( gen ) ];
    }
    return name_;
}
std::string Database::getRandomAddress()
{
     std::vector<std::string> address = {"Czekoladowa", "Truskawkowa", "Internetowa", "Bezprzewodowa", "Tesli", "McConora"};
     static std::random_device rd;
     static std::mt19937 gen( rd() );
     std::uniform_int_distribution<> random_address(0, address.size() - 1 );
     std::string address_ = address [ random_address( gen ) ];
     address_ += " " + std::to_string( random_address( gen ) + 1 );
     return address_;
}
std::string Database::getRandomPesel( Sex sex )
{
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_int_distribution<> random_pesel( 100'000'000, 999'999'999 );
    std::string pesel_ = std::to_string( random_pesel( gen ) );
    std::uniform_int_distribution<> random_sex_digit( 0, 4 );
    int base = 2 * random_sex_digit( gen );
    if( sex == Sex::male )
        ++base;
    pesel_ += std::to_string( base );
    std::uniform_int_distribution<> random_control_digit( 0, 9 );
    pesel_ += std::to_string( random_control_digit( gen ));
    return pesel_;
}
int Database::getRandomInt( unsigned int from, unsigned int to )
{
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_int_distribution<> random_index( from, to );
    int random_number = random_index( gen );
    return random_number;
}
PersonPtr Database::getRandomStudent()
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
PersonPtr Database::getRandomEmployee()
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
void Database::generate( int n = 40 )
{
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    for( int i = 0; i < n; ++i )
    {
        std::uniform_int_distribution<> random_person( 0, 1 );
        PersonPtr random_body = ( ( random_person( gen ) == 0 ) ? getRandomStudent() : getRandomEmployee() );
        allPeople.emplace_back( random_body );
    }
}
void Database::save( const std::string & file_name )
{
    std::ofstream ofs( file_name, std::ios::out);
    if(ofs.is_open())
    {
        ofs << *this;
        ofs.close();
    }
}
void Database::load( const std::string & file_name )
{
    std::ifstream ifs;
    ifs.open( file_name, std::ios::in );
    if( ifs.is_open() )
    {
        while( !ifs.eof() )
        {
            char type;
            ifs >> type;
            std::string broker;
            ifs >> broker;
            std::string name = broker;
            ifs >> broker;
            std::string surname = broker;
            ifs >> broker;
            std::string address = broker;
            ifs >> broker;
            address += " " + broker;
            ifs >> broker;
            Sex sex = ( broker[0] == 'f' ) ? Sex::female : Sex::male;
            ifs >> broker;
            std::string pesel = broker;
            int indexOrSalary;
            ifs >> indexOrSalary;
            PersonPtr p;
            switch( type )
            {
                case 'S': p = std::make_shared<Student>(name, surname, address, sex, Pesel(pesel), indexOrSalary ); break;
                case 'E': p = std::make_shared<Employee>(name, surname, address, sex, Pesel(pesel), indexOrSalary ); break;
            }
            if( p->isPeselValid() )
                add( std::move( p ) );
        }
    }
    ifs.close();
}
std::ostream& operator<<( std::ostream& os, const Database & database )
{
    const int WIDTH = 12;
    std::cout  << std::left
        << std::setw(WIDTH/2) << "TYPE"
        << std::setw(WIDTH)   << "NAME"
        << std::setw(WIDTH)   << "SURNAME"
        << std::setw(WIDTH*2) << "ADDRESS"
        << std::setw(WIDTH)   << "SEX"
        << std::setw(WIDTH)   << "PESEL"
        << std::setw(WIDTH)   << "INDEX"
        << std::setw(WIDTH)   << "SALARY" << std::endl;
    for (const auto & it : database.allPeople)
    {
           it->print(os);
           os << std::endl;
    }
    os << std::endl;
    return os;
}
