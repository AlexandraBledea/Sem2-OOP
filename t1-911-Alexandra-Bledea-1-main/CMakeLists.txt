cmake_minimum_required(VERSION 3.17)
project(t1_911_Alexandra_Bledea_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Console)
include_directories(Domain)
include_directories(DynamicArray)
include_directories(Repository)
include_directories(Service)

add_executable(t1_911_Alexandra_Bledea_1
        Console/Console.cpp
        Console/Console.h
        Domain/Gene.cpp
        Domain/Gene.h
        DynamicArray/dynamic_array.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/Service.cpp
        Service/Service.h
        Test/Test.cpp
        Test/Test.h
        start.cpp)
