main: main.o Strings.o MM.o
	cc -o main main.o Strings.o MM.o

main.o	: main.cpp Strings.hh
	cc -c main.cpp
Strings.o	: Strings.cc  MM.hh Strings.hh
	cc -c Strings.cc
MM.o	: MM.cc MM.hh
	cc -c MM.cc

clean	: 
	rm main main.o Strings.o MM.o
