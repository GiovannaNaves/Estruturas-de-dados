CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/queue.o $(OBJ)/main.o $(OBJ)/huffman.o
HDRS = $(INC)/queue.hpp $(INC)/huffman.hpp 
CFLAGS = -Wall -c -I$(INC) 

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) -c entrada.txt

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS) 

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

clean:
	rm -f $(EXE) $(OBJS)