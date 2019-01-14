CXX=c++
CXXFLAGS=-O0 -g -Wall -Wextra 

all: prime.x reverse.x sieve.x vector.x 

%.x:%.cc
	$(CXX) $(CXXFLAGS) -o $@ $<


.PHONY: clean

clean:
	rm -f *.x 
