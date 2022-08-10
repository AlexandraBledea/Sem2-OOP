cmake_minimum_required(VERSION 3.17)
project(a23_911_Alexandra_Bledea C)

set(CMAKE_C_STANDARD 11)

include_directories(console)
include_directories(domain)
include_directories(repository)
include_directories(service)
include_directories(DynamicArray)

add_executable(a23_911_Alexandra_Bledea
        console/console.c
        console/console.h
        domain/domain.c
        domain/domain.h
        repository/repository.c
        repository/repository.h
        undo_redo/repo_undo.c
        undo_redo/repo_undo.h
        DynamicArray/dynamic-array.c
        DynamicArray/dynamic-array.h
        service/service.c
        service/service.h
        validation/validation.c
        validation/validation.h
        tests/tests.c
        tests/tests.h
        main.c
        )
