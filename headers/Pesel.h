#pragma once
#include<string>
#include<ostream>
class Pesel
{
    std::string nr;
    int parseToInteger(char);
    int controlCoefficient(int);
    int giveControlDigit();
public:
    bool isControlDigitValid();
    int giveSexDigit();
    friend bool operator==(Pesel, Pesel);
    friend bool operator<=(Pesel, Pesel);
    friend std::ostream& operator<<(std::ostream&, const Pesel & p);
    Pesel() = default;
    Pesel(const std::string & nr) : nr(nr) {}
    Pesel(const Pesel & c) : nr(c.nr) {}
    ~Pesel() {}
};
