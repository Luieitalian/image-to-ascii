CC=gcc
CCFLAGS=-O2 -DNDEBUG
LDFLAGS=-lm
SRC=src
BIN=bin/main
OBJ=lib
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

all: $(BIN)

$(BIN): $(OBJS) $(OBJ)
	mkdir -p bin
	$(CC) $(CCFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $(OBJ)

run: $(BIN)
	./bin/main $(img).bmp

.PHONY: all
