#!/usr/bin/bash
cd GoogleTest
git clone https://github.com/google/googletest.git -b v1.14.0
cd googletest
mkdir build
cd build
cmake ..
make
sudo make install
cd ../..
mkdir build
cd build
cmake ..
make
echo
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo 
echo "GoogleTest/GoogleMock setup complete!"
echo "To make changes to, and re-build/run this project:"
echo "    1.) cd build"
echo "    2.) make"
echo "    3.) ./main.out"
echo
echo "Here is an example of this project's output when you run Google Test:"
echo
./main.out
echo
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
exit