#!/bin/bash
clear
mkdir build 2> /dev/null
cd build
cp ../lib/libSecret.so .
echo "Running 'cmake ..'"
cmake ..
echo; echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"; echo
echo "Running 'make'" 
make
echo; echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"; echo
echo "Output:"
Main.out
echo
exit