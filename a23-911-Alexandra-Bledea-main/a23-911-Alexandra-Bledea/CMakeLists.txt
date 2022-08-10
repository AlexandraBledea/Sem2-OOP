cmake_minimum_required(VERSION 3.17)
project(a23_911_Alexandra_Bledea C)

set(CMAKE_C_STANDARD 11)

include_directories(a23-911-Alexandra-Bledea/console)
include_directories(a23-911-Alexandra-Bledea/domain)
include_directories(a23-911-Alexandra-Bledea/repository)
include_directories(a23-911-Alexandra-Bledea/service)
include_directories(a23-911-Alexandra-Bledea/validation)

add_executable(a23_911_Alexandra_Bledea
        a23-911-Alexandra-Bledea/console/console.c
        a23-911-Alexandra-Bledea/console/console.h
        a23-911-Alexandra-Bledea/domain/domain.c
        a23-911-Alexandra-Bledea/domain/domain.h
        a23-911-Alexandra-Bledea/repository/repo_undo.c
        a23-911-Alexandra-Bledea/repository/repo_undo.h
        a23-911-Alexandra-Bledea/repository/repository.c
        a23-911-Alexandra-Bledea/repository/repository.h
        a23-911-Alexandra-Bledea/repository/UndoRedoRepository.c
        a23-911-Alexandra-Bledea/repository/UndoRedoRepository.h
        a23-911-Alexandra-Bledea/service/service.c
        a23-911-Alexandra-Bledea/service/service.h
        a23-911-Alexandra-Bledea/validation/validation.c
        a23-911-Alexandra-Bledea/validation/validation.h
        a23-911-Alexandra-Bledea/main.c)
