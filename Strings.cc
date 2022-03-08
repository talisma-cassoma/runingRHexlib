//-----standard c/c++---
#include <iostream> //contem as func memset(), memcpy() ... etc
#include <string.h> // holds strlen() function 
//---- headers------
#include "Strings.hh"
#include "MM.hh"

using namespace std;
 
static char * memCpy_cpp(const char * in_arr){ //cpy a const char* string to char* string
    
    size_t length = strlen(in_arr)+1;
    char * cpy= new char[length];
    
    if(cpy){memcpy(cpy, in_arr, length);} 
    return cpy;
}


Strings::Strings(int size):count(size){

     if((array = new const char * [count]) == NULL){
        MMFatalError("Strings::Strings", "new could not allocate enough memory");
    }
   }
Strings::Strings(const char ** in_array, int size): count(size){
    
    if((array = new const char * [count]) == NULL){
        MMFatalError("Strings::Strings", "new could not allocate enough memory");
    }
    for(int i=0; i< count; i++){
        if((array[i] = memCpy_cpp(in_array[i])) == NULL){
            MMFatalError("Strings::Strings", "new could not allocate enough memory");
        }
            cout<<array[i]<<endl; //...debuging  
    }
} 

void Strings::printChar(int pos){
    cout<<array[pos]<<endl;
}


