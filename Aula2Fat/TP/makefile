CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJSFAT = $(OBJ)/fatop.o $(OBJ)/fat.o 
HDRSFAT = $(INC)/fat.h 
OBJSFIB = $(OBJ)/fibop.o $(OBJ)/fib.o 
HDRSFIB = $(INC)/fib.h 
CFLAGS = -Wall -c -pg -ftest-coverage -I$(INC)

EXE = $(BIN)/fatop $(BIN)/fibop

run: $(EXE)
	$(BIN)/fatop
	$(BIN)/fibop

$(BIN)/fatop: $(OBJSFAT)
	$(CC) -pg -o $(BIN)/fatop $(OBJSFAT) $(LIBS) -pg

$(OBJ)/fatop.o: $(HDRSFAT) $(SRC)/fatop.c
	$(CC) $(CFLAGS) -o $(OBJ)/fatop.o $(SRC)/fatop.c

$(OBJ)/fat.o: $(HDRSFAT) $(SRC)/fat.c
	$(CC) $(CFLAGS) -o $(OBJ)/fat.o $(SRC)/fat.c


$(BIN)/fibop: $(OBJSFIB)
	$(CC) -pg -o $(BIN)/fibop $(OBJSFIB) $(LIBS) -pg

$(OBJ)/fibop.o: $(HDRSFIB) $(SRC)/fibop.c
	$(CC) $(CFLAGS) -o $(OBJ)/fibop.o $(SRC)/fibop.c

$(OBJ)/fib.o: $(HDRSFIB) $(SRC)/fib.c
	$(CC) $(CFLAGS) -o $(OBJ)/fib.o $(SRC)/fib.c
	
	
cleanfat:
	rm -f $(EXE) $(OBJSFAT) gmon.out

cleanfib:
	rm -f $(EXE) $(OBJSFIB) gmon.out