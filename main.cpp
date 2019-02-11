#include "headers/Database.h"

void PersonTest()
{
       Person person("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("01234567891"));
       std::cout << person;
}
void SearchingTest()
{
    Database database;
    database.add(Student("Robert", "Bomba", "Codeskulowa 69", Sex::male, Pesel("01234567891"), 12));
    database.add(Student("Anna", "Atraba", "Alarabiska 9", Sex::female, Pesel("11234567891"), 13));
    database.add(Student("Fiodor", "Cewski", "Petersburska 1", Sex::male, Pesel("21234567891"), 11));
    database.add(Student("Bo", "Atraba", "Youtubowska 5", Sex::female, Pesel("01234567891"), 46));
    StudentPtr sought = database.findByPesel("01234567891");
    std::cout << *sought << std::endl;
    std::vector<Student> candi = database.findBySurname("Atraba");
    for( auto & i : candi )
        std::cout << i << std::endl;
}
void GeneralTest()
{
    Database database;
    database.add(Student("Robert", "Bomba", "Codeskulowa 69", Sex::male, Pesel("01234567891"), 12));
    database.add(Student("Anna", "Atraba", "Alarabiska 9", Sex::female, Pesel("11234567891"), 13));
    database.add(Student("Fiodor", "Cewski", "Petersburska 1", Sex::male, Pesel("21234567891"), 11));
    database.show();
    database.sortByIndex();
    database.show();
    database.sortByPesel();
    database.show();
    database.sortBySurname();
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
    database.generate(10);
    database.show();
}
void PeselTest()
{
    if(Person("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("44051401358")).isPeselValid() == false)
        std::cout << "plec zgodna, kontrolna nie" << std::endl;
    if(Person("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("44051401359")).isPeselValid() == true)
        std::cout << "plec zgodna, kontrolna tez" << std::endl;
    if(Person ("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("44051401342")).isPeselValid() == false)
        std::cout << "plec niezgodna, kontrolna zgodna" << std::endl;
    if(Person ("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("44051401321")).isPeselValid() == false)
        std::cout << "plec niezgodna, kontrolna tez" << std::endl;
}
int main()
{
    PeselTest();
//    GenerateTest();
//    PersonTest();
//    GeneralTest();
//    SearchingTest();
    return 0;
}
