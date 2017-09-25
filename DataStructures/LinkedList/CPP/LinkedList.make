CC      = g++
CFLAGS  = -g -Wall
LDFLAGS = 


all: LinkedList

LinkedList.o: LinkedList.cpp
	$(CC) -c $(CFLAGS) $<

LinkedList: LinkedList.o
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm LinkedList LinkedList.exe
