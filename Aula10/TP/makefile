CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/arvexp.o 
CFLAGS = -Wall -c -I$(INC) 

EXE = $(BIN)/main

run:  $(EXE)
	clear
	$(EXE) 

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS) 

$(OBJ)/arvexp.o: $(SRC)/arvexp.c
	$(CC) $(CFLAGS) -o $(OBJ)/arvexp.o $(SRC)/arvexp.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out