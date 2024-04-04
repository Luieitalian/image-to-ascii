all: compile link run

compile:
	gcc -c main.c -o lib/main.o

link:
	gcc lib/main.o -o bin/main.exe

run:
	./bin/main.exe

.PHONY: all link compile