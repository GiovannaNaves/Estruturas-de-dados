CC = c++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/pilha.o $(OBJ)/funcoes.o $(OBJ)/arvore.o
HDRS = $(INC)/arvore.hpp $(INC)/funcoes.hpp $(INC)/pilha.hpp
CFLAGS = -Wall -c -I$(INC) -pg -ftest-coverage

EXE = $(BIN)/main

gprof: $(EXE)
	$(EXE) entrada.txt
	gprof -ftest-coverage -p $(EXE) gmon.out > /tmp/testegprof.txt

run:  $(EXE)
	clear
	$(EXE) entrada.txt

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS) -pg

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp 
	
$(OBJ)/funcoes.o: $(HDRS) $(SRC)/funcoes.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/funcoes.o $(SRC)/funcoes.cpp 

$(OBJ)/arvore.o: $(HDRS) $(SRC)/arvore.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/arvore.o $(SRC)/arvore.cpp 

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out