CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/avlorig.o 
CFLAGS = -Wall -c -I$(INC) 

EXE = $(BIN)/main

run:  $(EXE)
	clear
	$(EXE) 

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS) 

$(OBJ)/avlorig.o: $(SRC)/avlorig.c
	$(CC) $(CFLAGS) -o $(OBJ)/avlorig.o $(SRC)/avlorig.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out