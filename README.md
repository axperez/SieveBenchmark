# SieveBenchmark
Count prime numbers up to input n, given by command line argument.

## Instructions:
1. git clone https://github.com/axperez/SieveBenchmark.git
2. `cd SieveBenchmark/`
3. `make clean all`
4. Run with command line argument as n (number )
    * `./sieve n`


## Sieve Algorithm:
1. If n ≤ N and n is not prime, then n must be divisible by a prime not exceeding
√N. We first list all the integers between 2 and N : 

        2,3,4,5,...N

2. We then successively remove the following:
    * 4, 6, 8, 10, . . . , that is even integers from 22 onwards;

    * 9,15,21,27,..., that is all multiples of 3 from 32 onwards; 
    * 25, 35, 55, 65, . . . , that is all multiples of 5 from 52 onwards;

3. Continuing in this way we remove all those integers which are multiples of a prime not exceeding √N.

4. The remaining numbers are all the prime numbers not exceeding N.

## Input and Output:
**Input to the Algorithm:** A natural number N.

**Output of the Algorithm:** For the specified value of N obtain the following values:
1. The number of primes less than or equal to N. That is, the number π(N).
2. Therealnumber β(N).
3. The number of addition operations: A(N).
4. The number of multiplication operations M(N). Consider squaring to be a multi- plication operation.
5. Use a clock function to determine the time used in finding the prime numbers. Call it T(N). Initialize a counter with a clock at the beginning of the routine, and note the clock value at the end of the computations. And then take the difference. Use any unit of time.
