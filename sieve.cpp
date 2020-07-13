// =========================================================
//      sieve.cpp
// 
//      Benchmark algorithm: Return list of prime numbers up
//                           to and including n.
// ---------------------------------------------------------
// Author:      Axel Perez
// Date:        7/1/20
// Runtime:     O()
// =========================================================
#include <cmath>
#include <tuple>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


const unsigned int NUM_ITERS = 10;

tuple<unsigned int, double, unsigned int, unsigned int, double> sieve(unsigned int n) {
    auto start = chrono::high_resolution_clock::now();
    vector<bool> isPrime(n+1, true);
    unsigned int numPrimes = 0, numAdds = 0, numMults = 0, i, k;
    
 
    i = 2;
    numMults++;
    while (i*i <= n) {
        if (isPrime[i]) {
            k = i + i;
            numAdds++;

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

void sieveBenchmark(unsigned int n, unsigned int numIters) {
    double microsecSum = 0;
    tuple<unsigned int, double, unsigned int, unsigned int, double> output;

    for (int i = 0; i < numIters; i++) {
        output = sieve(n);
        microsecSum += get<4>(output);
    }

    cout << "\nNumber of Primes: " << get<0>(output) << endl;
    cout << "B(n) = " << get<1>(output) << endl;
    cout << "Number of Addition Operations: " << get<2>(output) << endl;
    cout << "Number of Multiplication Operations: " << get<3>(output) << endl;
    cout << "Avergae Time Elapsed (Average of " << numIters << " Iterations): ";
    cout << microsecSum/numIters << " msecs" << endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Error: Include unsigned integer as command line argument." << endl;
        return 1;
    }
    
    sieveBenchmark(atoi(argv[1]), NUM_ITERS);
    
    return 0;
}
