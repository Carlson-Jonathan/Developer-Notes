cmake_minimum_required(VERSION 3.1)
project(UnitTestExample)

set(UnitTest++_INCLUDE_DIRS "/usr/local/include/UnitTest++")
set(UnitTest++_LIBRARY_DIRS "/usr/local/include/UnitTest++/lib")
set(UnitTest++_LIBRARIES "UnitTest++")

add_executable(Main.out UnitTest++.cpp)

add_library(UNITTEST_LIB
    ../sourceCode.cpp
)
    
include_directories(Main.out PRIVATE 
    ${UnitTest++_INCLUDE_DIRS}
    ../
)

target_link_directories(Main.out PRIVATE 
    ${UnitTest++_LIBRARY_DIRS}
)

target_link_libraries(Main.out PRIVATE 
    UNITTEST_LIB
    ${UnitTest++_LIBRARIES}
)