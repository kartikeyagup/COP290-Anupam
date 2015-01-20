all:hello.o
	g++ -o hello.o

hello.o:factorial.cpp hello.cpp main.cpp functions.h
	g++  -c factorial.cpp hello.cpp main.cpp

clear:
	rm -rf *o hello
