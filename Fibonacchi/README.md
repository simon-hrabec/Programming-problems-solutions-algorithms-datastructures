# Fibonacchi

Fibanacchi sequence or Fibonacchi numbers are often mentioned in highschool and discreet mathematics in university, appears in nature, were used to model population of rabbits and sometimes can occur naturally in a problem. Fibonacchi number/sequence is defined as follows:
F(n) = f(n-1) + f(n-2) and having constraints f(1) = 1 and f(0) = 1

It is important to know that the number grows exponentially, even when the base is smaller than 2 (approximatelly something around 1.6). We can easily prove that the upper bound is 2 and the lower bound is sqrt(2) - the number doubles at least over 2 elements.

An easy approach to compute the fibonacchi number is to derive code durectly from the formula - write a recursive function that can look as follows:

int fibonacchi(int n){
  if (n <= 1)
    return 0;
  else
    return fibonacchi(n-1) + fibonacchi(n-2);
}

This is the naive solution. The advantage (the only) is its simplicity - it is obvious what it does and can be writen in just few seconds. The main disadvantage if this solution is that it take exponential time to compute (and linear space - which is not explicitly allocated, but is allocated implicitly on stack as the recursive call are performed). Due to its exponential time complexity this solution is infeasable, usable only for very small numbers.

What can we do better to improve the algorithm? We can observe from following picture that a lot of values are recomputed - an obvious idea might be to store the values in a cache and compute each value just once. This approach will reduce the time complexity to linear time (each call for different n is computed just once by asking for constant number of other entries). However the space coplexity stays the same - we will allocate the space to store the intermediate values and also the stack, both of size respective to n.

Another approach might be to try to solve this problem by hand and from such solution derive an algorithm. People would normally compute f(0), f(1) and from these compute f(2). Then they would use f(1) and f(2) to compute f(3) and then observe that you can continue and remember just 2 previous results. This can be writen as a simple for loop:

int fibonacchi(int n){
  int fib1 = 1;
  int fib2 = 1;
  for(int i = 1; i < n; i++){
    int temp = fib1 + fib2;
    fib1 = fib2;
    fib2 = temp;
  }
}

This has also linear time complexity and the space complexity is reduced to constant and also the algorithm is likely to work fast since a simple forcycle is easier for the computer to perform than function calls (if the tail recursion optimization is not used).

This might seems like the end, but there are better ways to go. One thing is that there is a direct formula to compute the fibanacchi number. For a homogenous linear recurrence with constant coefficients there is a way to get a direct formula and fibonacchi sequence fitting into this group alows us to do so. The solution is f(n) = (phi^n-phi^-n)/sqrt(5). One could be amazed that a direct formula can exist, but this way has its drawbacks - since we are dealine with irrational numbers there will be error and we might not round to the proper number. However such formula can be used in areas where we need just rought estimate.

Still, we can do better than linear time - there is a way to compute the number in logarithmic time (however with high hidden constants, so the linear algorithm can be faster). The trick is to express the fibonacchi numbers in a 2x2 matrix and use MMM (matrix-matrix multiplication) to compute the following elements. This itself would not reduce the time, however we can utilise the algorithm for exponentiation in logarithmic time.

XXX algorithm

In competetive programming a lot of results is requiered in the form of mudolo (the prime 1000000007 is used a lot) and thefore one could ask of milionth fibonacchi number and thats a number where the logaritmic version of fibonacchi computation algorithm beats the linear one.

There is one other observations to make fibonacchi numbers grow quite fast (exponentially to be exact) and therefore we run out of the 32/64 bit integer - fibonacchi(93) is the biggest that fits into 64 bits. Therefore we might need big integers (where number is stored in multiple integers) and it might further alter our complexity, since then we cannot count on basic operations between numbers being constant time. We already know that fibonacchi numbers grow exponentially but how fast do their representations in binary/decimal grow? A length of a number is a logarithmic function with base depending on the base used to show the numbers. Since logaritm and exponential function are inverse to each other, the result is that the size of the number grows lineary.
