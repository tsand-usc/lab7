# Lab 7 Debugging and Multithreading
gdb Section:
The factorial function was fixed by pre-decrementing n. Some how the function was only decrementing n once.

asan section:
To find the problem I read the lines ASAN listed as having a problem. That made it easier to determine why the quicksort function was having a problem. The program can bee fixed by reducing the value given to the quicksort function by 1. The value given for the top bound was the size of the array, not the size minus 1. This caused it to access a value at 6 did not exist. 


multithreading section: 
