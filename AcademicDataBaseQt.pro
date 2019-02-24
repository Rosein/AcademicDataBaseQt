TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    cpp/Database.cpp \
    cpp/Employee.cpp \
    cpp/Person.cpp \
    cpp/Pesel.cpp \
    cpp/Student.cpp \
    cpp/RandomPerson.cpp

HEADERS += \
    headers/Database.h \
    headers/Employee.h \
    headers/Person.h \
    headers/Pesel.h \
    headers/Student.h \
    headers/RandomPerson.h
