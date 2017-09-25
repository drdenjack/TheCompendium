CC      = g++
CFLAGS  = -g -Wall
LDFLAGS = 


all: BST

BST: BST.o
	$(CC) -o $@ $^ $(LDFLAGS)

BST.o: BST.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm BST BST.exe
