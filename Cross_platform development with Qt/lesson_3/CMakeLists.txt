cmake_minimum_required(VERSION 3.5)

project(lesson_3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lesson_3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        dialog.cpp dialog.h dialog.ui
    )

else()
    if(ANDROID)
        add_library(lesson_3 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(lesson_3
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(lesson_3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(lesson_3 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS lesson_3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lesson_3)
endif()
