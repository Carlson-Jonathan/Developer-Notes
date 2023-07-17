add_subdirectory(subDir2)

add_library(NEWTARGET_LIBS STATIC           # Include new .cpp lib(s)
    newTarget.cpp
)

target_link_libraries(NEWTARGET_LIBS        # Link new lib(s) with child libs from other folder(s).
    NEWTARGET2_LIBS
)

target_include_directories(Main.out PRIVATE
    subDir2
)
