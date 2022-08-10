cmake_minimum_required(VERSION 3.17)
project(t2_911_Alexandra_Bledea_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(BMI)
include_directories(BP)
include_directories(Console)
include_directories(Exceptions)
include_directories(Measurement)
include_directories(Person)
include_directories(Validation)

add_executable(t2_911_Alexandra_Bledea_1
        BMI/BMI.cpp
        BMI/BMI.h
        BP/BP.cpp
        BP/BP.h
        Console/Console.cpp
        Console/Console.h
        Exceptions/ExceptionPerson.cpp
        Exceptions/ExceptionPerson.h
        Measurement/Measurement.cpp
        Measurement/Measurement.h
        Person/Person.cpp
        Person/Person.h
        Validation/Validation.cpp
        Validation/Validation.h
        main.cpp)
