all:	sieve.cpp
		g++ -std=c++11 -o sieve sieve.cpp
debug:	sieve.cpp
		g++ -std=c++11 -g -o sieve sieve.cpp
clean:
		rm -rf *.o *~ sieve core