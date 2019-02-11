 #include "headers/Database.h"

void PersonTest()
{
       Person person("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("01234567891"));
       std::cout << person;
}

int main()
{
//    PersonTest();
    Database database;
    database.add(Student("Robert", "Traba", "Codeskulowa 69", Sex::male, Pesel("01234567891"), 12));
    database.add(Student("Anna", "Bomba", "Alarabiska 9", Sex::female, Pesel("01234567891"), 13));
    database.add(Student("Fiodor", "Jewski", "Petersburska 1", Sex::male, Pesel("01234567891"), 11));
    database.show();
    database.sort();
    database.show();
    database.remove(13);
    database.show();
    std::cout << std::endl;
    return 0;
}
