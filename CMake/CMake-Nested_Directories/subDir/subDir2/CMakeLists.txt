add_subdirectory(subDir3)

add_library(NEWTARGET2_LIBS STATIC
    newTarget2.cpp
    ${NEWTARGET2_LIBS}
)

target_include_directories(Main.out PRIVATE
    subDir3
)

target_link_libraries(NEWTARGET2_LIBS
    NEWTARGET3_LIBS
)