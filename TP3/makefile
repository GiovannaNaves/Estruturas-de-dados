CC = c++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/queue.o 
HDRS = $(INC)/queue.hpp
CFLAGS = -Wall -c -I$(INC) -pg -ftest-coverage

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS) -pg

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/queue.o: $(HDRS) $(SRC)/queue.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/queue.o $(SRC)/queue.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out