CC = c++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/fatop.o $(OBJ)/fat.o 
HDRS = $(INC)/fat.h 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/fatop

run:  $(EXE)
	$(EXE)


$(BIN)/fatop: $(OBJS)
	$(CC) -pg -o $(BIN)/fatop $(OBJS) $(LIBS)

$(OBJ)/fatop.o: $(HDRS) $(SRC)/fatop.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fatop.o $(SRC)/fatop.cpp

$(OBJ)/fat.o: $(HDRS) $(SRC)/fat.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fat.o $(SRC)/fat.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out