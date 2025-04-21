cmake_minimum_required(VERSION 3.5)

project(samp2_2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    dialog.cpp
    dialog.h
    dialog.ui
    res.qrc         #添加资源文件
    appIcon.rc      #添加应用程序图标资源文件
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(samp2_2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(samp2_2
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(samp2_2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(samp2_2)
endif()
