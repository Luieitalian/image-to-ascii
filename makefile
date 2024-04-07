all: compile link run

compile:
	gcc -c main.c -o lib/main.o
	gcc -c bmp_config.c -o lib/bmp_config.o
	gcc -c bitmap.c -o lib/bitmap.o
	gcc -c brightness.c -o lib/brightness.o
	gcc -c ascii_matrix.c -o lib/ascii_matrix.o

link:
	gcc lib/bmp_config.o lib/bitmap.o lib/brightness.o lib/ascii_matrix.o lib/main.o -o bin/main.exe

run:
	./bin/main.exe $(img).bmp

.PHONY: all compile link run