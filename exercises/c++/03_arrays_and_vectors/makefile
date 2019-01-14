CXX=c++
CXXFLAGS=-O0 -g -Wall -Wextra 

all: optional.x avoid_repeated.x mean_median.x transpose.x
%.x:%.cc
	$(CXX) $(CXXFLAGS) -o $@ $<


.PHONY: clean

clean:
	rm -f *.x 
