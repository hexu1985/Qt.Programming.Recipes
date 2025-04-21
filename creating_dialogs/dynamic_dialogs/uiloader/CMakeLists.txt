cmake_minimum_required(VERSION 3.5)

project(uiloader VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets UiTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets UiTools REQUIRED)

set(PROJECT_SOURCES
    mywidget.cpp
    mywidget.h
    first.ui
    second.ui
    uiloader.qrc
    main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(uiloader
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(uiloader
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(uiloader PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::UiTools)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(uiloader)
endif()
