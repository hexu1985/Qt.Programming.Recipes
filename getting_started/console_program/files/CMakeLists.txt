cmake_minimum_required(VERSION 3.5)

project(files VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

### test data_file
set(DATA_FILES mydata)

foreach(data_file ${DATA_FILES})
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${data_file}
        #COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/${data_file}
                ${CMAKE_CURRENT_BINARY_DIR}/${data_file}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${data_file}
        COMMENT "Copying test data_file ${data_file}"
    )
endforeach()

add_custom_target(copy_data_files ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/mydata
)

set(PROJECT_SOURCES
    qdemo.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(files
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(files
        ${PROJECT_SOURCES}
    )
endif()

add_dependencies(files copy_data_files)
target_link_libraries(files PRIVATE Qt${QT_VERSION_MAJOR}::Core)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(files)
endif()
