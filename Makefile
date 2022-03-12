main : main.o Strings.o MM.o
	g++ -o main main.o Strings.o MM.o

main.o : main.cpp Strings.h
	g++ -o main.o main.cpp -c -W -Wall -ansi -pedantic
Strings.o : Strings.cpp  MM.h Strings.h
	g++ -o Strings.o Strings.cpp -c -W -Wall -ansi -pedantic
MM.o	: MM.cpp MM.h
	g++ -o MM.o MM.cpp -c -W -Wall -ansi -pedantic

#elimina todos aquivos .o e os arquivos de backup ~
clean: 
	rm -rf *.o *~ 
