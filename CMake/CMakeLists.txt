# See https://learnxinyminutes.com/docs/cmake/
# Using g++ you would link library files using a command like: 
#     g++ main.cpp calculator.cpp textOutputter.cpp
# Here is how you do it with CMake (very stripped down):
# Create a file named "CMakeLists.txt" in your main directory and edit it like so:

# 1.) Create a library variable that houses your .cpp files.
#         * The first parameter sets a variable for your library.
#         * The second parameter can be STATIC or SHARED.
#             - STATIC means the libraries are compiled into the executable and generates not extra files.
#             - SHARED means libraries are referenced during runtime and generates '.dll' (Windows) files.
add_library(My_Libraries STATIC "calculator.cpp" "textOutputter.cpp")

# 2.) Create an executable. Call the add_executable function.
#         * Param1 is your executable name
#         * Param2 is the primary file to compile.
add_executable(Main.out main.cpp)

# 3.) Link the executable to the library variable.
target_link_libraries(Main.out My_Libraries)

# To build using cmake, create an empty directory (probably called 'build') in your main directory.
# cd into that directory and run the command 'cmake ..'. This will build files to that directory.
# If building succeeds, run the command 'make' which will create your executable in the build directory.
