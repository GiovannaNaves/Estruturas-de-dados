CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o

CFLAGS = -Wall -c -I$(INC) -pg

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) pontos.txt

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS) -pg

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out