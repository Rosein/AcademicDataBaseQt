#include "headers/Employee.h"

Employee::Employee( const char name[],
				                const char surname[],
				                const char address[],
				                Sex sex,
				                Pesel pesel) 
    : Person(name,surname,address,sex,pesel)
{
}


Employee::~Employee()
{
}
