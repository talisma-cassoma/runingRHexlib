#lets start
PROJ_NAME=letsRun_

# headers directory
HEADERS_DIR = include

#get all .c files from proj dir
CPP_SOURCE=$(wildcard ./base/*.cpp)

#get all .hpp files from proj dir 
H_SOURCE=$(wildcard ./include/*.hpp)

#get all objects files 
OBJ=$(subst .cpp,.o,$(subst base,objects,$(CPP_SOURCE)))

#decide compiler and linker 
CC=g++

# warning flags just in case of error 

CC_FLAGS=-c       \
         -W       \
		 -Wall    \
		 -ansi    \
		 -pedantic \
		 -I$(HEADERS_DIR) # tells the compiler where headers live (i.e. in the "include" directory).

# cmd for clean target 
RM =rm -rf

#--COMPILATION and LINKING STEPS--

all: objectsDir $(PROJ_NAME)

#exec traget 
$(PROJ_NAME): $(OBJ) 
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' ' 

./objects/%.o: ./base/%.cpp ./include/%.hpp	
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@

./objects/main.o: ./base/main.cpp $(H_SOURCE)
	$(CC) $< $(CC_FLAGS) -o $@

./objects/Module.o: ./base/Module.cpp $(H_SOURCE)
	$(CC) $< $(CC_FLAGS) -o $@

objectsDir:
	@ mkdir -p objects

clean: 
	$(RM) ./objects/*.o *~ $(PROJ_NAME)
	rmdir objects

.PHONY: all clean
#fonte de leitura: "introdução ao Makefile" no portal https://www.embarcados.com.br/
