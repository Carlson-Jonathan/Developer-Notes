cmake_minimum_required(VERSION 3.1)
project(VanillaUnitTestExample)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})        
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/lib)

add_library(MYLIB SHARED ../sourceCode.cpp)
add_executable(Main.out testHarness.cpp)

include_directories(../)

target_link_libraries(Main.out 
    MYLIB
)

target_compile_options(Main.out PRIVATE -Wall -Werror)