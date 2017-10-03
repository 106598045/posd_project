INC_DIR = include
SRC_DIR = src

all: hw2

hw2: main.o number.o variable.o atom.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 main.o number.o variable.o atom.o -lgtest
else
	g++ -o hw2 main.o number.o variable.o atom.o -lgtest -lpthread
endif

main.o: main.cpp utTerm.h
	g++ -std=gnu++0x -c main.cpp
number.o:$(INC_DIR)/variable.h $(INC_DIR)/number.h $(SRC_DIR)/number.cpp $(INC_DIR)/atom.h
	g++ -std=gnu++0x -c $(SRC_DIR)/number.cpp
variable.o:$(SRC_DIR)/variable.cpp $(INC_DIR)/number.h $(INC_DIR)/atom.h $(INC_DIR)/variable.h
	g++ -std=gnu++0x -c $(SRC_DIR)/variable.cpp
atom.o: $(INC_DIR)/atom.h $(INC_DIR)/number.h $(INC_DIR)/variable.h $(SRC_DIR)/atom.cpp
		g++ -std=gnu++0x -c $(SRC_DIR)/atom.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o exp
endif
