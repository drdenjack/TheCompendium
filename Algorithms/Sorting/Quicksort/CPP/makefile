CC      = g++
CFLAGS  = -g -Wall
LDFLAGS = 


all: QuickSort

QuickSort: QuickSort.o
	$(CC) -o $@ $^ $(LDFLAGS)

QuickSort.o: QuickSort.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm QuickSort QuickSort.exe
