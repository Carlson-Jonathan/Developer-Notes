add_subdirectory(subDir2)

add_library(NEWTARGET_LIBS STATIC
    newTarget.cpp
    ${NEWTARGET2_LIBS}
)

target_include_directories(Main.out PRIVATE
    subDir2
)

target_link_libraries(NEWTARGET_LIBS
    NEWTARGET2_LIBS
)
