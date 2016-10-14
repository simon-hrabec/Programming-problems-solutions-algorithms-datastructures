# Ndimensional dynamic array
Background motivation:

Declaring multidimensinal static array in C++ is easy and works well - you just write T arr[xsize][ysize][zsize] or T arr[][][] = {{{1},{3},{4}},{{6},{0},{1}}}, or it is possible to use the std::array feature. However declaring dynamic array with multiple dimension is not that easy. To use the multiple square bracket (2D) you need to allocate a array of pointers and for each entry allocate a single row/collumn. Then it is possible to you arr[x][y], but performancewise this approach is not good - lets see the following picture (ADD PICTURE). There is several huge problems:
- the more dimensions you have, the more for cyclec you need to write to initialize the array
- There are a lot of pointers wasting space, that are not present in the static array.
- Also it results in more levels of indirection - which will requiere a computer to read at many places in memory to access a single element
- if we iterate over the elements we jump over the memory (depends where the memory was allocated, performance can differ) and thats bad for the cache (poor space locality)
- many allocations are deffinitely worse than a single allocation (since it is a system call)
- memory ends up less fragmented
- inpropper access (forgetting one bracket) can modify the pointer and then lead to memory leakage

An example of arrays of pointers:
int xsize, ysize;
int ** arr = new int*[xsize];
for(int i = 0; i < xize; i++){
	arr[i] = new int[ysize];
}

arr[5][1] = 125;

Another approach is to allocate a single block and then recalculate the index. This is what is actually done with static arrays, because the sizes are known in advance, all the accesses can be recomputed, similarly to pointer arithmetics (compiler knows the size of the element). It can work in this way:

int xsize, ysize;
int * arr = new int[xsize*yize];
int x, y;
arr[x*ysize+y] = 10;
Insted of using two brackets we use just one and we need to recompute the index. This is a bit too complicated to use, but performancewise this is the way to have the same performance as the static array. Thats why I wanted to make a custom class (container) to have dynamic multidimensional arrays which are easy to use.

Notes, implementation

I want to have/achieve:
- make this container for arbitarly dimension - I hope this can be achieved effectively with template metaprogramming, otherwise I would have to make exact class for few dimensions (because normally people use 2D, 3D, max 5D) and more general but not efficient universal solution for higher dimmensions
- I would like to include optional boundary checking that could be turned on for debuging purposes and turned off without any performance loss (difference made on compile time, via templates)
- Make the container as STL-like as possible, making it universal.

I decided to start with 2D array and later generalise it to multiple dimensions.
