all: compile link run

compile:
	gcc -c main.c  -o lib/main.o
	gcc -c bmp_config.c -o lib/bmp_config.o

link:
	gcc lib/main.o lib/bmp_config.o -o bin/main.exe

run:
	./bin/main.exe

.PHONY: all compile link run