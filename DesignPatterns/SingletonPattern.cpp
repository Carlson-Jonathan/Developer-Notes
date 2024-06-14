/****************************************************************************** 
 * Singleton Example
 *     Only one instance of a singleton object can exist at a time. All other 
 *     attempts to create an object from this class will result in pointers to
 *     the first object created. This is good for setting globally accessable
 *     objects while eliminating the need to pass pointers around to access it.
 ******************************************************************************/

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
using namespace std;
    
class Singleton {
public:
    Singleton(const Singleton& obj) = delete; // 1.) Delete the copy constructor.

    static Singleton* getInstance() {         // 2.) Set a static getter.
    	if(!instancePtr)                       
            instancePtr = new Singleton();
        return instancePtr;
    }

    string someString;

private:
    Singleton() {}                            // 3.) Make the default constructor 
                                              //     private to prevent misuse.
    static Singleton* instancePtr;            // 4.) Set a static pointer to THIS.
};
                                            
Singleton* Singleton::instancePtr = NULL;     // 5.) Set the pointer to NULL.

// Singleton* someSingleton = Singleton::getInstance();  6.) Use in your code.

#endif // SINGLETON_H
