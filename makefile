#INC_DIR = include
#SRC_DIR = src

all: hw3

hw3: main.o variable.o number.o atom.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 main.o variable.o number.o atom.o struct.o -lgtest
else
	g++ -o hw3 main.o variable.o number.o atom.o struct.o -lgtest -lpthread
endif
#-------------------------------------------------

main.o: main.cpp utStruct.h utAtom.h atom.h struct.h
	 	g++  -std=gnu++0x -c  main.cpp

variable.o:variable.cpp number.h atom.h variable.h
		g++ -std=gnu++0x -c variable.cpp
#-------------------------------------------------
number.o:variable.h number.h number.cpp atom.h
		g++ -std=gnu++0x -c number.cpp
#-------------------------------------------------
atom.o: atom.h number.h variable.h atom.cpp
		g++ -std=gnu++0x -c atom.cpp
#-------------------------------------------------
struct.o: struct.h atom.h struct.cpp
		g++ -std=gnu++0x -c struct.cpp

clean:
ifeq (${OS}, Windows_NT)
		del *.o *.exe
else
		rm -f *.o hw3
endif
