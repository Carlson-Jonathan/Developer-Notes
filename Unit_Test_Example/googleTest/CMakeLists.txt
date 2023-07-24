cmake_minimum_required(VERSION 3.1)
project(GoogleTestExample)
find_package(GTest REQUIRED)

add_library(GTEST_LIBS 
    ../sourceCode.cpp
)

include_directories(../)

add_executable(Main.out gTests.cpp)

target_link_libraries(Main.out PRIVATE 
    GTest::GTest 
    GTEST_LIBS
)
