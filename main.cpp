#pragma once
#include "headers/Database.h"
#include <fstream>

void SearchingTest()
{
    Database database;
    database.add( std::make_shared<Student>("Robert", "Bomba", "Codeskulowa 69", Sex::male, Pesel("01234567891"), 12) );
    database.add( std::make_shared<Student>("Anna", "Atraba", "Alarabiska 9", Sex::female, Pesel("11234567891"), 13) );
    database.add( std::make_shared<Student>("Fiodor", "Cewski", "Petersburska 1", Sex::male, Pesel("21234567891"), 11) );
    database.add( std::make_shared<Student>("Bo", "Atraba", "Youtubowska 5", Sex::female, Pesel("01234567891"), 46) );
    PersonPtr sought = database.findByPesel("01234567891");
    sought ->print(std::cout);
    std::cout << std::endl;
    People candi = database.findBySurname("Atraba");
    for( auto & i : candi )
    {
        i->print(std::cout);
        std::cout << std::endl;
    }
}
void GeneralTest()
{
    Database database;
    database.add( std::make_shared<Student>("Robert", "Bomba", "Codeskulowa 69", Sex::male, Pesel("01234567891"), 13));
    database.add( std::make_shared<Student>("Anna", "Atraba", "Alarabiska 9", Sex::female, Pesel("11234567891"), 12));
    database.add( std::make_shared<Student>("Fiodor", "Cewski", "Petersburska 1", Sex::male, Pesel("21234567891"), 11));
    database.add( std::make_shared<Employee>("Robert", "Bomba", "Codeskulowa 69", Sex::male, Pesel("76545323154"), 120));
    database.add( std::make_shared<Employee>("Anna", "Atraba", "Alarabiska 9", Sex::female, Pesel("67121510396"), 103));
    database.add( std::make_shared<Employee>("Fiodor", "Cewski", "Petersburska 1", Sex::male, Pesel("32132132121"), 110));
    database.setSalary("32132132121",1000);
    database.show();
    database.sortByIndex();
    database.show();
    database.sortByPesel();
    database.show();
    database.sortBySurname();
    database.show();
    database.sortBySalary();
    database.show();
    database.removeByIndex(13);
    database.show();
    database.removeByPesel("01234567891");
    database.show();
    std::cout << std::endl;
}
void GenerateTest()
{
    Database database;
    database.generate(50);
    database.show();
}
void PeselTest()
{
    if(Student("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("44051401358"), 1111).isPeselValid() == false)
        std::cout << "plec zgodna, kontrolna nie" << std::endl;
    if(Student("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("44051401359"), 123123).isPeselValid() == true)
        std::cout << "plec zgodna, kontrolna tez" << std::endl;
    if(Student("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("44051401342"), 123123).isPeselValid() == false)
        std::cout << "plec niezgodna, kontrolna zgodna" << std::endl;
    if(Student("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("44051401321"), 123123).isPeselValid() == false)
        std::cout << "plec niezgodna, kontrolna tez" << std::endl;
}
void SaveTest(){
    Database database;
    database.generate(50);
    database.save("out.txt");
}
void LoadTest()
{
    Database database;
    database.load("in.txt");
    database.show();
}

int main()
{
    LoadTest();
    SaveTest();
    PeselTest();
    GenerateTest();
    GeneralTest();
    SearchingTest();
    return 0;
}
