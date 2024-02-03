#include <iostream>
#include "math.h"
#include "secret.h"
using namespace std;

int main() {

    cout << "Hello world!" << endl;

    Math object;
    cout << "8 + 4 = " << object.add(4, 8) << endl;

    cout << "CMake variable: " << CMAKE_VARIABLE << endl;
    cout << "Here is a secret message:\n"; 
    Secret::message();
    

    return 0;
}
