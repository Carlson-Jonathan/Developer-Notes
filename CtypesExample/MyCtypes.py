'''
Python 'ctypes' is a library that lets you call functions from C and C++ libraries (*.so files).
This is advantageous because Python can be slow where the C languages are very fast.
Here is a basic example of how to use Python ctypes to link to C++ library functions.
1.) Compile your C++ code into a shared library:
    (g++ command) g++ -fPIC -shared -o myLibraries.so myLibraries.cpp
    ...or just use CMake.
2.) Create a variable in Python that represents the C++ library file.
3.) Create Python variables that represent the individual functions you wish to use.
4.) Set the parameter types based on ctypes' type syntax.
5.) Call your functions like usual.    
'''

import ctypes
 
lib = ctypes.CDLL('libs/libLIBRARIES.so')

addTwoNumbers = lib.addTwoNumbers
addTwoNumbers.argtypes = [ctypes.c_int, ctypes.c_int]
addTwoNumbers.restype = ctypes.c_int

subtractTwoNumbers = lib.subtractTwoNumbers
subtractTwoNumbers.argtypes = [ctypes.c_int, ctypes.c_int]
subtractTwoNumbers.restype = ctypes.c_int

multiplyTwoNumbers = lib.multiplyTwoNumbers
multiplyTwoNumbers.argtypes = [ctypes.c_int, ctypes.c_int]
multiplyTwoNumbers.restype = ctypes.c_int

divideTwoNumbers = lib.divideTwoNumbers
divideTwoNumbers.argtypes = [ctypes.c_int, ctypes.c_int]
divideTwoNumbers.restype = ctypes.c_int

a = 999
b = 111
print("\n\nUsing numbers %i, and %i" %(a, b))
print("Adding in Python:", addTwoNumbers(a, b))
print("Subtracting in Python:", subtractTwoNumbers(a, b))
print("Multiplying in Python:", multiplyTwoNumbers(a, b))
print("Dividing in Python:", divideTwoNumbers(a, b))
print("\n\n")