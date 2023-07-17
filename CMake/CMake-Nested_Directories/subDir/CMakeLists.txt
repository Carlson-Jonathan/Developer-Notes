add_subdirectory(subDir2)

add_library(NEWTARGET1_LIBS STATIC
    sources/newTarget1.cpp
)

target_include_directories(NEWTARGET1_LIBS PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers           # Needed to find newTarget1.h
)                                                 # CMAKE_CURRENT_SOURCE_DIR is optional.

target_link_libraries(NEWTARGET1_LIBS
    NEWTARGET2_LIBS                               # Links child's libraries to executable (the next folder down)
)