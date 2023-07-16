cmake_minimum_required(VERSION 3.10)
project(ModularNested)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

add_executable(Main.out main.cpp)

add_subdirectory(${CMAKE_SOURCE_DIR}/subDir)    # reads the CMakeLists.txt file from here

target_include_directories(Main.out PRIVATE     # Where to look for header files.
    ${CMAKE_SOURCE_DIR}/subDir
)

target_link_libraries(Main.out                  # Where to look for source files.
    NEWTARGET_LIBS                              # (This var is created in the next folder down)
)
