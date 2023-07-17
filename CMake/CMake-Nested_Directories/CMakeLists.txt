cmake_minimum_required(VERSION 3.10)
project(ModularNested)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

add_executable(Main.out main.cpp)
add_subdirectory(subDir)                         # Reads the CMakeLists.txt file of this directory

target_link_libraries(Main.out PRIVATE           # Where to look for source files.
    NEWTARGET1_LIBS                              # Links child's libraries to executable (the next folder down)
)