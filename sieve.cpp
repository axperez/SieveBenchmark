// =========================================================
//      sieve.cpp
// 
//      Sieve of Erastosthenes Becnhmark: 
//          Count prime numbers up to input n, given by 
//          command line arg
// ---------------------------------------------------------
// Author:      Axel Perez
// Date:        7/1/20
// Runtime:     O(NUM_ITERS*n*log(log(n)))
// =========================================================

// Included Libraries
#include <cmath>
#include <tuple>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <regex>

using namespace std;

// Constant
const unsigned int NUM_ITERS = 10;

//  Sieve of Erastosthenes Algorithm:
//      Counts the amount of prime numbers, additions, and multiplications less than
//      or equal to input n. Also calculates B(N) and times the algorithm.
//
//      Input:
//          unsigned int n: Natural number to get primes up to.
//
//      Output:
//          tuple<unsigned int,     : Number of primes less than or equal to input n
//                double,           : B(N)
//                unsigned int,     : Number of additions
//                unsigned int,     : Number of multiplications
//                double>           : Time elapsed in milliseconds
tuple<unsigned int, double, unsigned int, unsigned int, double> sieve(unsigned int n) {
    auto start = chrono::high_resolution_clock::now();
    vector<bool> isPrime(n+1, true);    // Using index as actual number
    unsigned int numPrimes = 0, numAdds = 0, numMults = 0, i, k;
    
    i = 2;  // start at 2 (0 and 1 are not primes by definition)
    numMults++;
    while (i*i <= n) {
        if (isPrime[i]) {
            k = i + i;
            numAdds++;
            // If prime, set all multiples of prime to false
            while (k <= n) {
                isPrime[k] = false;
                k = k + i;
                numAdds++;
            }
        }
        i++;
        numAdds++;
        numMults++;
    }
    // Count all the prime numbers left
    for (i = 2; i < n; i++, numAdds++) {
        if (isPrime[i]) {
            numPrimes++;
            numAdds++;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> dur = end - start;
    
    return make_tuple(numPrimes, (numPrimes/(n/log(n))), numAdds, numMults, dur.count());
}

//  Sieve Benchmark Test:
//      Runs the sieve algorithm numIters times and prints the average time elapsed
//      with number of primes, B(N), number of additions, and number of multiplications.
//
//      Input:
//          unsigned int n: Natural number to get primes up to.
//          unsigned int numIters: Number of iterations to run sieve algorithm.
void sieveBenchmark(unsigned int n, unsigned int numIters) {
    double microsecSum = 0;
    tuple<unsigned int, double, unsigned int, unsigned int, double> output;

    for (int i = 0; i < numIters; i++) {
        output = sieve(n);
        microsecSum += get<4>(output);
    }

    cout << "\nNumber of Primes: " << get<0>(output) << endl;
    cout << "B(N) = " << get<1>(output) << endl;
    cout << "Number of Addition Operations: " << get<2>(output) << endl;
    cout << "Number of Multiplication Operations: " << get<3>(output) << endl;
    cout << "Avergae Time Elapsed (Average of " << numIters << " Iterations): ";
    cout << microsecSum/numIters << " msecs" << endl;
}

int main(int argc, char *argv[]) {
    // Error handling
    if (argc != 2 || !regex_match(argv[1], regex("[1-9](\\d)*"))) {
        cout << "Error: Include one natural number (integer greater than zero) as command line argument." << endl;
        return 1;
    }
    
    sieveBenchmark(atoi(argv[1]), NUM_ITERS);
    
    return 0;
}
