CC      = g++
CFLAGS  = -g -Wall
LDFLAGS = 


all: linkedlist

linkedlist: linkedlist.o
	$(CC) -o $@ $^ $(LDFLAGS)

linkedlist.o: LinkedList.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm linkedlist
