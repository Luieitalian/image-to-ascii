all: compile link run

compile:
	gcc -c main.c -o lib/main.o
	gcc -c src/bmp_config.c -o lib/bmp_config.o
	gcc -c src/bitmap.c -o lib/bitmap.o
	gcc -c src/brightness.c -o lib/brightness.o
	gcc -c src/ascii_matrix.c -o lib/ascii_matrix.o
	gcc -c src/utils.c -o lib/utils.o

link:
	gcc lib/bmp_config.o lib/bitmap.o lib/brightness.o lib/ascii_matrix.o lib/utils.o lib/main.o -o bin/main.exe

run:
	./bin/main.exe $(img).bmp

.PHONY: all compile link run