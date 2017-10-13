CC      = g++
CFLAGS  = -g -Wall
LDFLAGS = 


all: Stack_extras

Stack_extras: Stack_extras.o
	$(CC) -o $@ $^ $(LDFLAGS)

Stack_extras.o: Stack_extras.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm Stack_extras Stack_extras.exe
