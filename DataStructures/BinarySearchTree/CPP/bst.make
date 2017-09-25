CC      = g++
CFLAGS  = -g -Wall
LDFLAGS = 


all: bst

bst: bst.o
	$(CC) -o $@ $^ $(LDFLAGS)

bst.o: BST.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm bst
