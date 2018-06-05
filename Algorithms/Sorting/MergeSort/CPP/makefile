CC      = g++
CFLAGS  = -g -Wall
LDFLAGS = 


all: MergeSort

MergeSort: MergeSort.o
	$(CC) -o $@ $^ $(LDFLAGS)

MergeSort.o: MergeSort.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm MergeSort MergeSort.exe
