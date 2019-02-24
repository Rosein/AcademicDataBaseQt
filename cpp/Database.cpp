#include "headers/Database.h"

void Database::add( PersonPtr && person )
{
       allPeople.emplace_back( person );
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
    std::sort(allPeople.begin(),allPeople.end(), ComparerIndex() );
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
    std::sort(allPeople.begin(),allPeople.end(), ComparerSurname() );
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

void Database::generate( int n = 40 )
{
    for( int i = 0; i < n; ++i )
    {
        PersonPtr random_body = RandomPerson().generate();
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
