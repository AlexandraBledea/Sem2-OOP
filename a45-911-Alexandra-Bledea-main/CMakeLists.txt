cmake_minimum_required(VERSION 3.17)
project(a45_911_Alexandra_Bledea)


set(CMAKE_CXX_STANDARD 14)
include_directories(Console)
include_directories(Domain)
include_directories(DynamicArray)
include_directories(Repository)
include_directories(Service)
include_directories(Tests)
include_directories(Validation)

add_executable(a45_911_Alexandra_Bledea
        Console/console.cpp
        Console/console.h
        Domain/domain.cpp
        Domain/domain.h
        DynamicArray/dynamic_array.h
        Repository/repository.cpp
        Repository/repository.h
        Service/service.cpp
        Service/service.h
        Validation/validation.cpp
        Validation/validation.h
        Tests/test_domain.cpp
        Tests/test_domain.h
        Tests/test_repository.cpp
        Tests/test_repository.h
        Tests/test_repository.h
        Tests/test_dynamic_array.cpp
        Tests/test_dynamic_array.h
        Tests/test_service.cpp
        Tests/test_service.h
        Tests/test_validation.cpp
        Tests/test_validation.h
        start.cpp)