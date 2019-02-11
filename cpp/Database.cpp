#include "headers/Database.h"
#include <algorithm>

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
void Database::remove(int nr_index)
{
    int i;
    for( i = 0; i < allPeople.size(); ++i )
        if (allPeople[i].getIndex() == nr_index)
        {
            allPeople.erase(allPeople.begin() + i);
            break;
        }
}
Database::Database()
{
}
Database::~Database()
{
}
