all: hw8 shell

hw8: main.o list.o atom.o struct.o  scanner.h  parser.h exp.h
ifeq (${OS}, Windows_NT)
	g++ -o hw8 main.o list.o atom.o struct.o -lgtest
else
	g++ -o hw8 main.o list.o atom.o struct.o -lgtest -lpthread
endif

shell: shell.o list.o struct.o atom.o
ifeq (${OS}, Windows_NT)
	g++ -o shell shell.o atom.o list.o struct.o -lgtest
else
	g++ -o shell shell.o atom.o list.o struct.o -lgtest -lpthread
endif

shell.o: shell.cpp parser.h scanner.h
	g++ -std=gnu++0x -c shell.cpp

main.o: main.cpp exception.h scanner.h expression.h parser.h
	g++ -std=gnu++0x -c main.cpp

atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp

struct.o:struct.cpp struct.h atom.o
		 g++ -std=gnu++0x -c struct.cpp

list.o: list.cpp list.h atom.o
		g++ -std=gnu++0x -c list.cpp

clean:
	rm -f *.o hw8 shell
stat:
	wc *.h *.cpp
hw:
	make clean make hw8./hw8
