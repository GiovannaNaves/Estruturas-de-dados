CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/point.o $(OBJ)/convexhull.o
HDRS = $(INC)/point.hpp $(INC)/convexhull.hpp
CFLAGS = -Wall -c -I$(INC) -pg

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) pontos.txt

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS) -pg

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/point.o: $(HDRS) $(SRC)/point.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/point.o $(SRC)/point.cpp 

$(OBJ)/convexhull.o: $(HDRS) $(SRC)/convexhull.cpp 
	$(CC) $(CFLAGS) -o $(OBJ)/convexhull.o $(SRC)/convexhull.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out