#ifndef BUILDING
#define BUILDING

#include <iostream>
using namespace std;

class Building {
public:

    void buildCommands() {
        cout << "\nBUILD COMMANDS:\n\n"
             << "   There are several commands you can use to build that all " 
             <<    "pretty much do the same thing:\n"
             << "   Method 1:\n"
             << "      mkdir build\n"
             << "      cd build\n"   
             << "      cmake ..\n"
             << "      make\n\n"
             << "   Method 2:\n"
             << "      cmake -H. -Bbuild           (Creates the build directory and begins a build using it)\n"
             << "      cmake --build build -- -j3  (Runs make and creates an executable. When updating a\n"
             << "                                   source code change, only this line is needed.)\n\n";
    }
};

#endif // BUILDING
