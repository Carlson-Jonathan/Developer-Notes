add_library(NEWTARGET3_LIBS STATIC
    sources/newTarget3.cpp                          # Works with or without using
)                                                   # ${CMAKE_CURRENT_SOURCE_DIR}

target_include_directories(NEWTARGET3_LIBS PUBLIC
    headers
)