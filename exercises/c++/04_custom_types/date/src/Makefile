IDIR=../include
CC=g++
CFLAGS=-O0 -ggdb -Wall -Wextra -I$(IDIR)

ODIR=obj

_DEPS = date.h
# $(patsubst pattern,replacement,text)
# here pattern=%, which acts as a wildcard
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o date.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main.x: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

documentation: ../doc/Doxyfile
	doxygen $^

.PHONY: documentation
