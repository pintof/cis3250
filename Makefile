all: main

main: main.c connect.h
	gcc -Wall -pedantic -std=c99 main.c -o main
