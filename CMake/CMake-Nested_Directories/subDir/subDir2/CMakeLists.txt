add_subdirectory(subDir3)

add_library(NEWTARGET2_LIBS STATIC
    newTarget2.cpp                              # Unlike the this directory's parent and child folders,
)                                               # the header and source files are in the same directory
                                                # as the CMakeLists.txt file, just as an example.
target_include_directories(Main.out PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(NEWTARGET2_LIBS
    NEWTARGET3_LIBS
)