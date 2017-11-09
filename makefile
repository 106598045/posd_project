INC_DIR = include
SRC_DIR = src
BIN_DIR = bin

all: hw5

hw5: main.o term.o variable.o struct.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 main.o term.o variable.o struct.o list.o -lgtest
else
	g++ -o hw5 main.o term.o variable.o struct.o list.o -lgtest -lpthread
endif
#-------------------------------------------------

main.o: main.cpp utStruct.h atom.h struct.h
	 	g++  -std=gnu++0x -c  main.cpp

variable.o: variable.cpp number.h atom.h variable.h
		g++ -std=gnu++0x -c variable.cpp
#-------------------------------------------------
term.o: term.h variable.h term.cpp
		g++ -std=gnu++0x -c term.cpp
#-------------------------------------------------
#number.o:${INC_DIR}/variable.h ${INC_DIR}/number.h ${SRC_DIR}/number.cpp ${INC_DIR}/atom.h
#		g++ -std=gnu++0x -c ${SRC_DIR}/number.cpp
#-------------------------------------------------
#atom.o: ${INC_DIR}/atom.h ${INC_DIR}/number.h ${INC_DIR}/variable.h ${SRC_DIR}/atom.cpp
#		g++ -std=gnu++0x -c ${SRC_DIR}/atom.cpp
#-------------------------------------------------
struct.o: struct.h atom.h struct.cpp
		g++ -std=gnu++0x -c struct.cpp
#-------------------------------------------------
list.o: list.h list.cpp
		g++ -std=gnu++0x -c list.cpp

clean:
ifeq (${OS}, Windows_NT)
		del *.o *.exe
else
		rm -f *.o hw5
endif
