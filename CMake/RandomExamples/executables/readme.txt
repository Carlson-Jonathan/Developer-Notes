The Static.out file has the libraries embeded in the executable and is stand-alone.
The Shared.out file depends on the 2 *.so library files, which must be in the same directory.
Notice if you rename, move, or delete them, the Shared.out executable no longer works.