The Static.out file has the libraries embeded in the executable and is stand-alone.
The Shared#.out files depend on the 2 *.so library files, which must be in the same directory.
Notice if you rename, move, or delete either of them, the Shared#.out executables no longer work.
The Static.out file is 55Kb, whereas the Shared#.out files are 17Kb ea.
The libraries' and a Shared#.out file's total size is less than the Static.out file (50 vs 55).