CC      = g++
CFLAGS  = -g -Wall
LDFLAGS = 


all: SudokuSolver

SudokuSolver: SudokuSolver.o
	$(CC) -o $@ $^ $(LDFLAGS)

SudokuSolver.o: SudokuSolver.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm SudokuSolver SudokuSolver.exe
