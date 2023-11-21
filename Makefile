APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

flags = -lglut -lGLU -lGL -Wall

all: libed myapps

libed: 
	g++ -c $(SRC)/display.cpp -I $(INCLUDE) -o $(OBJ)/display.o $(flags)
	g++ -c $(SRC)/individuos.cpp -I $(INCLUDE) -o $(OBJ)/individuos.o
	g++ -c $(SRC)/functions.cpp -I $(INCLUDE) -o $(OBJ)/functions.o
	g++ -c $(SRC)/evolucao.cpp -I $(INCLUDE) -o $(OBJ)/evolucao.o	
	
myapps:
	g++ $(APPS)/main.cpp $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/main $(flags)

run:
	$(BIN)/main

clear:
	rm $(BIN)/* $(OBJ)/*

# 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