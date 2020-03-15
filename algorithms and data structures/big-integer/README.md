# Big integer
Some problems (e.g. Project Euler on Hackerrank) requieres the usage of numbers bigger than 32/64 bits in binary representations. Such situation requieres a representation of such numbers in a fast a convenient way. Some languages has a data type big integer built inside (C#, Java, Python), but C++ lasks such feature, therefore it needs to be implemented when desired to use. I want to provide you with my implementation of big integer, which supports the following:
- To make a big integer from a string in decimal representation
- Print a big integer in decimal form
- sum two big integers
- multiply two big integers
- expinentiate big integer
- compute a sum of its digits

Following things can (and in future will) be implemented:
- Make a big integer from a stgring in binary representation

Implementation detayls:
The big integer is represented as an array of 32-bit integers, where each integer represent 9 decimal numbers. Then operations as multiplication or addition are performed on simple integers. For addition a number can be at most 1 digit longer than the longer one (33 bits maximum), but for multiplication we can get up to sum of the lengths - 64 bits. Therefore 64 bit is used for the operations and the more significant part is then also processed.

Possible improvements:
TBA
