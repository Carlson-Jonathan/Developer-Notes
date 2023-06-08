cmake_minimum_required(VERSION 3.22)                   # Should always be the first line
project(MyNewCmake VERSION 1.0)                        # Name of project. Version optional. Affects output files.

set(CMAKE_BINARY_DIR       ${CMAKE_SOURCE_DIR}/[bin])  # Set Directories
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})        # Generated files (libs and .out) will be created here.
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 11)                             # Setup C++ version
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(My_Libraries STATIC                        # Include libraries in this folder
    "calculator.cpp" 
    "textOutputter.cpp"
)

add_executable(Main.out ${CMAKE_SOURCE_DIR}/main.cpp)  # Name your executable

add_subdirectory(${CMAKE_SOURCE_DIR}/newSubDir)

option(OPTION_FILES "Random Message." ON)              # Create an option variable for excluding code
if(OPTION_FILES)                                                       
  add_subdirectory(${CMAKE_SOURCE_DIR}/optionalSubDir)
  list(APPEND EXTRA_LIBS Optional_Files)                                # Create a list variable for libraries.
  list(APPEND EXTRA_INCLUDES "${CMAKE_SOURCE_DIR}/optionalSubDir")      # Create a list variable for includes.
  add_definitions(-DOPTIONS_ON)
endif()
                             
target_link_libraries(Main.out                          # Links executable to libraries (may include lists of libs)
    My_Libraries
    This_SubDir_Files
    ${EXTRA_LIBS}
)

target_include_directories(My_Libraries PUBLIC          # Tells the executable where to look for files to include.
                           "${CMAKE_BINARY_DIR}" 
                           "${CMAKE_SOURCE_DIR}/newSubDir"
                           "${EXTRA_INCLUDES}"
)
