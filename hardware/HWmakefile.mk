# esse trecho deve ser compilado antes do main 
# headers directory
HEADERS_DIR = include

#get all .c files from proj dir
CPP_SOURCE=$(wildcard ./hardware/*.cpp)

#get all .hpp files from proj dir 
H_SOURCE=$(wildcard ./include/*.hpp)

#get all objects files 
OBJ=$(subst .cpp,.o,$(subst hardware,objects,$(CPP_SOURCE)))

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

objectsDir:
	@ mkdir -p objects

./objects/%.o: ./hardware/%.cpp ./include/%.hpp	
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
