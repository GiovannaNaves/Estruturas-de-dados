CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/geraarvbin.o 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	clear
	$(EXE) -o saida.txt -s 10 -n 10

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/geraarvbin.o: $(SRC)/geraarvbin.c
	$(CC) $(CFLAGS) -o $(OBJ)/geraarvbin.o $(SRC)/geraarvbin.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out