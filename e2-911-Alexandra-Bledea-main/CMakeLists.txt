cmake_minimum_required(VERSION 3.19)
project(e2_911_Alexandra_Bledea)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw73_64\\lib\\cmake\\")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Charts Qt5::Gui Qt5::Widgets)


include_directories(Domain)
include_directories(Repository)
include_directories(Service)
include_directories(GUI)
include_directories(Observer)
include_directories(TableModel)

add_executable(e2_911_Alexandra_Bledea
        Domain/Ethnologist.cpp
        Domain/Ethnologist.h
        Domain/Building.cpp
        Domain/Building.h
        Repository/BuildingsRepo.cpp
        Repository/BuildingsRepo.h
        Repository/PeopleRepo.h
        Repository/PeopleRepo.cpp
        main.cpp TableModel/TableModel.cpp TableModel/TableModel.h Observer/Observer.h Service/Service.cpp Service/Service.h GUI/PersonWindow.cpp GUI/PersonWindow.h)


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})