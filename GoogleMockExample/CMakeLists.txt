cmake_minimum_required(VERSION 3.13)
project(GoogleTestExample)
find_package(GTest REQUIRED)

set (LIBS_DIR "../googletest/build/lib")
link_directories(${LIBS_DIR})

add_executable(main.out main.cpp)

target_link_libraries(main.out PRIVATE 
    GTest::GTest 
    libgmock.a
    libgmock_main.a
    pthread
)