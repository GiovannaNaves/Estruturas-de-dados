CC = c++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJSFAT = $(OBJ)/fatop.o $(OBJ)/fat.o 
HDRSFIB = $(INC)/fat.h 
OBJSFAT = $(OBJ)/fibop.o $(OBJ)/fib.o 
HDRSFIB = $(INC)/fib.h 
CFLAGS = -Wall -c -I$(INC)

EXEFAT = $(BIN)/fatop
EXEFIB = $(BIN)/fibop

fat:  $(EXEFAT)
	$(EXEFAT)

fib: $(EXEFIB)
	$(EXEFIB)


$(BIN)/fatop: $(OBJSFAT)
	$(CC) -pg -o $(BIN)/fatop $(OBJSFAT) $(LIBS)

$(OBJ)/fatop.o: $(HDRSFAT) $(SRC)/fatop.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fatop.o $(SRC)/fatop.cpp

$(OBJ)/fat.o: $(HDRSFAT) $(SRC)/fat.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fat.o $(SRC)/fat.cpp



$(BIN)/fibop: $(OBJSFIB)
	$(CC) -pg -o $(BIN)/fibop $(OBJSFIB) $(LIBS)

$(OBJ)/fibop.o: $(HDRSFIB) $(SRC)/fibop.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fibop.o $(SRC)/fibop.cpp

$(OBJ)/fib.o: $(HDRSFIB) $(SRC)/fat.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fib.o $(SRC)/fib.cpp
	
cleanfat:
	rm -f $(EXE) $(OBJSFAT) gmon.out

cleanfib:
	rm -f $(EXE) $(OBJSFIB) gmon.out