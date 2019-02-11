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

//std::ostream& Database::operator<<(std::ostream& os)
//{
//	for (auto & it : allPeople)
//		os << it << std::endl;
//	return os;
//}
void Database::sort()
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
void Database::remove(int nr_index)
{
    int i;
    for( i = 0; i < allPeople.size(); ++i )
        if (allPeople[i].getIndex() == nr_index)
        {
            allPeople.erase(allPeople.begin() + i);
            break;
        }
	/*Student sought_student = Student(nr_index);
	const auto sought = std::find(allPeople.begin(), allPeople.end(), sought_student);
	if (sought != allPeople.end())
	{
		allPeople.erase(sought);
	}*/
}
Database::Database()
{
}

Database::~Database()
{
}
