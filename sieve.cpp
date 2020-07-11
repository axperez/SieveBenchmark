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

using namespace std;

const unsigned int MAXNUM = 10;


tuple<int, double, int, int, double> sieve(unsigned int n) {
    auto start = chrono::high_resolution_clock::now();
    bool isPrime[n+1];
    int numPrimes = 0, numAdds = 0, numMults = 0, i, k;
    
    for (i = 2; i < n+1; i++, numAdds++) {
        isPrime[i] = true;
    }
    
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
            cout << "DEBUG: " << i << endl;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> dur = end - start;
    
    return make_tuple(numPrimes, (n/log(n)), numAdds, numMults, dur.count());
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Error: Include unsigned integer as command line argument." << endl;
        return 1;
    }
    auto output = sieve(atoi(argv[1]));

    cout << "\nNumber of Primes: " << get<0>(output) << endl;
    cout << "B(n) = " << get<1>(output) << endl;
    cout << "Number of Addition Operations: " << get<2>(output) << endl;
    cout << "Number of Multiplication Operations: " << get<3>(output) << endl;
    cout << "Time elapsed: " << get<4>(output) << " msecs" << endl;

    return 0;
}
