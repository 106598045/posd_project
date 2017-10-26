INC_DIR = include
SRC_DIR = src
BIN_DIR = bin

all: hw3

hw3: main.o term.o variable.o struct.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 main.o term.o variable.o struct.o list.o -lgtest
else
	g++ -o hw3 main.o term.o variable.o struct.o list.o -lgtest -lpthread
endif
#-------------------------------------------------

main.o: main.cpp utStruct.h ${INC_DIR}/atom.h ${INC_DIR}/struct.h
	 	g++  -std=gnu++0x -c  main.cpp

variable.o: ${SRC_DIR}/variable.cpp ${INC_DIR}/number.h ${INC_DIR}/atom.h ${INC_DIR}/variable.h
		g++ -std=gnu++0x -c ${SRC_DIR}/variable.cpp
#-------------------------------------------------
term.o: ${INC_DIR}/term.h ${INC_DIR}/variable.h ${SRC_DIR}/term.cpp
		g++ -std=gnu++0x -c ${SRC_DIR}/term.cpp
#-------------------------------------------------
#number.o:${INC_DIR}/variable.h ${INC_DIR}/number.h ${SRC_DIR}/number.cpp ${INC_DIR}/atom.h
#		g++ -std=gnu++0x -c ${SRC_DIR}/number.cpp
#-------------------------------------------------
#atom.o: ${INC_DIR}/atom.h ${INC_DIR}/number.h ${INC_DIR}/variable.h ${SRC_DIR}/atom.cpp
#		g++ -std=gnu++0x -c ${SRC_DIR}/atom.cpp
#-------------------------------------------------
struct.o: ${INC_DIR}/struct.h ${INC_DIR}/atom.h ${SRC_DIR}/struct.cpp
		g++ -std=gnu++0x -c ${SRC_DIR}/struct.cpp
#-------------------------------------------------
list.o: ${INC_DIR}/list.h ${SRC_DIR}/list.cpp
		g++ -std=gnu++0x -c ${SRC_DIR}/list.cpp

clean:
ifeq (${OS}, Windows_NT)
		del *.o *.exe
else
		rm -f *.o hw3
endif
