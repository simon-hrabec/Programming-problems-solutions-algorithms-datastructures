Efficient implementation of the union find (UF) data structure.

It uses path reconnection to the root on find operation and merging based on sizes of trees to achieve the optimal complexity.

The class also contains an utility function to get the current number of groups/segments as the cost of tracking this is just a integer decrementation on a merge operation (performed on different groups).
