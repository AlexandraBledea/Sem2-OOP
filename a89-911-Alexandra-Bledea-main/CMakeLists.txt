cmake_minimum_required(VERSION 3.17)
project(a89_911_Alexandra_Bledea)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw73_64\\lib\\cmake\\")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Charts Qt5::Gui Qt5::Widgets)

include_directories(AbstractShoppingBasket)
include_directories(Console)
include_directories(CSVShoppingBasket)
include_directories(Domain)
include_directories(DynamicArray)
include_directories(Exceptions)
include_directories(FileRepository)
include_directories(HTMLShoppingBasket)
include_directories(Repository)
include_directories(Service)
include_directories(Tests)
include_directories(Validation)
include_directories(GUI)
include_directories(AdminModeGUI)
include_directories(UserModeGUI)

add_executable(a89_911_Alexandra_Bledea
        AbstractShoppingBasket/AbstractShoppingBasket.cpp
        AbstractShoppingBasket/AbstractShoppingBasket.h
        Console/console.cpp
        Console/console.h
        CSVShoppingBasket/CSVShoppingBasket.cpp
        CSVShoppingBasket/CSVShoppingBasket.h
        Domain/domain.cpp
        Domain/domain.h
        DynamicArray/dynamic_array.h
        Exceptions/Exceptions.cpp
        Exceptions/Exceptions.h
        FileRepository/FileRepository.cpp
        FileRepository/FileRepository.h
        HTMLShoppingBasket/HTMLShoppingBasket.cpp
        HTMLShoppingBasket/HTMLShoppingBasket.h
        Repository/repository.cpp
        Repository/repository.h
        Service/service.cpp
        Service/service.h
        Tests/test_domain.cpp
        Tests/test_domain.h
        Tests/test_dynamic_array.cpp
        Tests/test_dynamic_array.h
        Tests/test_repository.cpp
        Tests/test_repository.h
        Tests/test_service.cpp
        Tests/test_service.h
        Tests/test_validation.cpp
        Tests/test_validation.h
        Validation/validation.cpp
        Validation/validation.h
        GUI/GUI.h
        GUI/GUI.cpp
        start.cpp UserModeGUI/UserModeGUI.cpp UserModeGUI/UserModeGUI.h AdminModeGUI/AdminModeGUI.cpp AdminModeGUI/AdminModeGUI.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})