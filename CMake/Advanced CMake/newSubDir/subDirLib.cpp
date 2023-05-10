#include "subDirLib.h"

void SubDirLib::aboutSubDir() {
    cout << "SUB DIRECTORIES:\n\n"
         << "   Files placed in subdirectories in your project can be accessed with CMake's 'add_subdirectory()' function!\n"
         << "   Example: add_subdirectory(${CMAKE_SOURCE_DIR}/newSubDir ${CMAKE_BINARY_DIR})\n"
         << "   Each sub directory must contain its own 'CMakeLists.txt' file. This file will include the add_libray()\n"
         << "   function. The name of the library variable will be unique to that particular folder. All '.cpp' files\n"
         << "   in the sub directory folder will be added via that function.\n\n"
         << "   The executable must be updated to include the new library variable. This can be done in the subdirectory,\n"
         << "   but should be done in the root folder for better organization. Update the target_link_libraries() function.\n"
         << "   Just add the new library variable. Also update the target_include_directories function.\n\n\n";
};