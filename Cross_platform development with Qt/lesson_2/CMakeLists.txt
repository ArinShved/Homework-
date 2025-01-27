cmake_minimum_required(VERSION 3.14)

project(lesson_2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Sql Network)

add_executable(lesson_2
  main.cpp
)

target_link_libraries(lesson_2 Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(lesson_2 Qt${QT_VERSION_MAJOR}::Sql)
target_link_libraries(lesson_2 Qt${QT_VERSION_MAJOR}::Network)

install(TARGETS lesson_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
