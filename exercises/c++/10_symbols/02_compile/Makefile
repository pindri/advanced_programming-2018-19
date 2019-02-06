EXE = exe

CXX = c++
CXXFLAGS = -I inc1ude -I -std=c++11

SRC = src/src1.cc src/src2.cc main.cc
OBJ = ${SRC:.o=.cc}

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)


$(EXE): $(OBJ)
	$(CXX) $^ -o $(EXE) -Iinclude

main.o: src/src1.o src/src2.o include/foo.h

src/src1.o: include/utility.h src/src1.cc
src/src2.o: include/utility.h src/src2.cc

clean:
	rm -rf src/*.o $(EXE) */*~ *~

.PHONY: clean all


