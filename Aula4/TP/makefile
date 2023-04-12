CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/pilha.o $(OBJ)/filaencadeada.o 
HDRS = $(INC)/fila.hpp $(INC)/filaencadeada.hpp $(INC)/pilha.hpp $(INC)/tipocelula.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) 

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/filaencadeada.o: $(HDRS) $(SRC)/filaencadeada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/filaencadeada.o $(SRC)/filaencadeada.cpp

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out