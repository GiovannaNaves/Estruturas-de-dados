CC = c++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/pilha.o $(OBJ)/funcoes.o $(OBJ)/arvore.o
HDRS = $(INC)/arvore.hpp $(INC)/fila.hpp $(INC)/funcoes.hpp $(INC)/pilha.hpp $(INC)/tipoitem.hpp $(INC)/tipono.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	clear
	$(EXE) < entrada.txt

$(BIN)/main: $(OBJS)
	$(CC)  -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp 
	
$(OBJ)/funcoes.o: $(HDRS) $(SRC)/funcoes.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/funcoes.o $(SRC)/funcoes.cpp 

$(OBJ)/arvore.o: $(HDRS) $(SRC)/arvore.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/arvore.o $(SRC)/arvore.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out