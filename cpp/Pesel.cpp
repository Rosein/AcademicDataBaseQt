#include "headers/Pesel.h"

int Pesel::parseToInteger(char digit)
{
    return static_cast<int>(digit - '0');
}
int Pesel::controlCoefficient(int i)
{
    int mod = i % 4;
    switch(mod)
    {
    case 0: return  9;
    case 1: return  7;
    case 2: return  3;
    case 3: return  1;
    }
}
bool Pesel::isValid()
{
    
    if (nr.empty() || nr.size() != 11)
        return false;
    int control_sum = 0;
    for (auto i = 0; i < nr.size() - 1; ++i)
        control_sum += controlCoefficient(i) * parseToInteger(nr[i]);
    return control_sum % 10 == parseToInteger(nr[nr.size() - 1]);
}

std::ostream& operator<<(std::ostream& os, const Pesel & p)
{
   	return os << p.nr;
}
bool operator==(Pesel first, Pesel second)
{
   	return first.nr == second.nr;
}
