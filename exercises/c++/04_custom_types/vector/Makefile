CXX=c++
CXXFLAGS=-O0 -g -std=c++14 -Wall -Wextra 

all: vector.x
%.x:%.cc
	$(CXX) $(CXXFLAGS) -o $@ $<


.PHONY: clean

clean:
	rm -f *.x 
