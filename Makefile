all:	sieve.cpp
		g++ -o sieve sieve.cpp
debug:	sieve.cpp
		g++ -g -o sieve sieve.cpp
clean:
		rm -rf *.o *~ sieve core