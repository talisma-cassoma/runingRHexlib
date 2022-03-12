Main : main.o Strings.o MM.o
	g++ -o Main main.o Strings.o MM.o

main.o : main.cc Strings.h
	g++ -o main.o main.cc -c -W -Wall -ansi -pedantic
Strings.o : Strings.cc  MM.h Strings.h
	g++ -o Strings.o Strings.cc -c -W -Wall -ansi -pedantic
MM.o	: MM.cc MM.h
	g++ -o MM.o MM.cc -c -W -Wall -ansi -pedantic

#elimina todos aquivos .o e os arquivos de backup ~
clean: 
	rm -rf *.o *~ 
