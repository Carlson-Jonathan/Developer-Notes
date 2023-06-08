cmake_minimum_required(VERSION 3.1)
project(Mine)

set(CMAKE_BINARY_DIR       ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/../libs)

add_library(LIBRARIES SHARED
    myLibraries.cpp
)

add_executable(Main.out main.cpp)

target_link_libraries(Main.out LIBRARIES)