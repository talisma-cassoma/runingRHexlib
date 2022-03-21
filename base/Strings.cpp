//-----standard c/c++---
#include <iostream> //here lives the func memset(), memcpy() ... etc
#include <string.h> // holds strlen() function 
//---- headers------
#include "Strings.hpp"
#include "MM.hpp"

using namespace std;
 
static char * memCpy(const char * in_arr){ //
    
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
        if((array[i] = memCpy(in_array[i])) == NULL){
            MMFatalError("Strings::Strings", "new could not allocate enough memory");
        }
            //cout<<array[i]<<endl; //...debuging  
    }
}

// copy c-tor
Strings::Strings( Strings& str ){           
    
    count = str.getCount();
    if((array = new const char * [count]) == NULL){
        MMFatalError("Strings::Strings", "new could not allocate enough memory");
    }
    for(int i=0; i< count; i++){
        if((array[i] = memCpy(str.get(i) )) == NULL){
            MMFatalError("Strings::Strings", "new could not allocate enough memory");
        }
           // cout<<array[i]<<endl; //...debuging  
    }
    
}

//d-tor
Strings::~Strings( void ){
    for(int i=0; i<count; i++){
        if(array[i]){ delete [] array[i];}
    }
    if(array){ delete [] array;}
} 

Strings& Strings::operator= ( Strings& str ){
    if(this == &str){return *this;}
    
    this->~Strings(); // I think this way more usufull
    
    count = str.getCount();
    
    if((array = new const char * [count]) == NULL){
        MMFatalError("Strings::operator=", "new could not allocate enough memory");
    }
    for(int i=0; i< count; i++){
        if((array[i] = memCpy(str.get(i))) == NULL){
            MMFatalError("Strings::operator=", "new could not allocate enough memory");
        }
            //cout<<array[i]<<endl; //...debuging  
    }
    
 return *this;   
}

// get function- gets the string at particular index
const char * Strings::get( int index ){
  if( index >= count || index < 0 ){MMFatalError( "Strings::get", "Index is out of range!" );}
  return array[index];
}

// set function- sets the string at a particular index to s
void Strings::set( const char * str, int index ){
  if( index >= count || index < 0 ){
    MMFatalError( "Strings::set", "Index is out of range!" );
  }
  if( array[index] ){ delete[] array[index];}
  if( (array[index] = memCpy( str )) == NULL ){
    MMFatalError( "Strings::set", "mystrdup failed" );
  }
}