CC=gcc
CFLAGS= -Wall -pedantic -std=c99

SRCDIR = ./src/


runMe:
	$(CC) $(CFLAGS) -Iinclude $(SRCDIR)mainCalculator.c $(SRCDIR)largeFunctions.c $(SRCDIR)helperFunctions.c -o runMe

clean:
	rm runMe
