INC_DIR = include
SRC_DIR = src

all: hw3

#未完成測試
hw3: main.o variable.o number.o atom.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 main.o variable.o number.o atom.o struct.o -lgtest
else
	g++ -o hw3 main.o variable.o number.o atom.o struct.o -lgtest -lpthread
endif
#-------------------------------------------------

main.o: main.cpp utStruct.h utAtom.h $(INC_DIR)/atom.h $(INC_DIR)/struct.h
	g++ -std=c++11 -c main.cpp

variable.o:$(SRC_DIR)/variable.cpp $(INC_DIR)/number.h $(INC_DIR)/atom.h $(INC_DIR)/variable.h
			g++ -std=gnu++0x -c $(SRC_DIR)/variable.cpp
#-------------------------------------------------
number.o:$(INC_DIR)/variable.h $(INC_DIR)/number.h $(SRC_DIR)/number.cpp $(INC_DIR)/atom.h
					g++ -std=gnu++0x -c $(SRC_DIR)/number.cpp
#-------------------------------------------------
atom.o: $(INC_DIR)/atom.h $(INC_DIR)/number.h $(INC_DIR)/variable.h $(SRC_DIR)/atom.cpp
		g++ -std=gnu++0x -c $(SRC_DIR)/atom.cpp
#-------------------------------------------------
struct.o: $(INC_DIR)/struct.h $(INC_DIR)/atom.h $(SRC_DIR)/struct.cpp
		g++ -std=gnu++0x -c $(SRC_DIR)/struct.cpp

clean:
ifeq (${OS}, Windows_NT)
		del *.o *.exe
else
		rm -f *.o hw3
endif
