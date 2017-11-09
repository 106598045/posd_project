all: hw5

hw5: mainParser.o atom.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 mainParser.o atom.o list.o -lgtest
else
	g++ -o hw5 mainParser.o atom.o list.o -lgtest -lpthread
endif

mainParser.o: mainParser.cpp utParser.h
	g++ -std=gnu++11 -c mainParser.cpp

atom.o: atom.cpp atom.h
	g++ -std=gnu++11 -c atom.cpp

list.o: list.cpp list.h variable.h
	g++ -std=gnu++11 -c list.cpp

clean:
	rm -f *.o hw5
stat:
	wc *.h *.cpp
