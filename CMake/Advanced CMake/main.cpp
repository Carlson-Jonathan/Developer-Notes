#include <iostream>
#include "calculator.h"
#include "textOutputter.h"
#include "building.h"
#include "newSubDir/subDirLib.h"
using namespace std;

#ifdef OPTIONS_ON
    #include "optionalSubDir/optionalCode.h"
#endif

int main() {

    // A few throw-away objects for CMake to round up.
    Calculator calculator;
    TextOutputter gib;
    Building buildNotes;
    SubDirLib subDirCode;

    buildNotes.buildCommands();
    subDirCode.aboutSubDir();

    #ifdef OPTIONALCODE_H
        OptionalCode options;
        options.aboutOption();
    #endif

    return 0;
}