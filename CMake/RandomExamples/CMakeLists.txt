cmake_minimum_required(VERSION 3.12)
project(MyProject)

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

add_library(Math STATIC ${CMAKE_SOURCE_DIR}/src/math.cpp)

add_executable(Main.out main.cpp)

set(LIBS
    ${CMAKE_SOURCE_DIR}/lib/libSecret.so # Link a pre-built shared library (no source code)
    Math                                 # Link the static library we just created above
)

target_link_libraries(Main.out PRIVATE 
    ${LIBS}
)

target_include_directories(Main.out PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
) 

target_include_directories(Math PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)


# 'target_include_directories()' assigns directories with header files to specific individual targets.
# Therefore it must be called once per target as seen above. On the other hand you can use
# 'include_directories()' below to apply the header directories to ALL targets. This is simpler
# but can have some unwanted side-effects in large projects.
# Basically, every 'add_library()' call must be paired with a 'target_include_directories()' call.
# In this example Main.out has a 'target_include_directories()' call because we are linking a
# pre-made shared library to it and CMake needs to know where that library's headers are.
# Often you will see library names set in a variable and the calls consolidated using a 'foreach' loop.

#include_directories(Main.out PRIVATE ${CMAKE_SOURCE_DIR}/include)


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# An example of setting and passing a CMake variable to C++
set(SOMEVARIABLE 90210)
target_compile_definitions(Main.out PUBLIC CMAKE_VARIABLE=${SOMEVARIABLE})
