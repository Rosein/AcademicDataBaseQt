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
    database.remove(13);
    database.show();
    std::cout << std::endl;
}
int main()
{
//    PersonTest();
//    GeneralTest();
//    SearchingTest();
    return 0;
}
