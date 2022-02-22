#include <iostream> //contem as func memset(), memcopy() ... etc
#include <stdio.h>
#include <ctype.h>

#include "Strings.hh"
#include "ModuleManagerMessages.hh"

using namespace std;

static const char* mystrdup( const char* in_string )
{
   size_t csize;
    char* zret;

  csize = strlen ( in_string ) + 1;
  zret = new char[csize];
  if( zret ){memcpy (zret, in_string, csize);} 
  return zret;
}

Strings(int in_count):count(in_count){
  if((array = new const char*[in_count])=NULL){
    MMFatalError("Strings::Strings",
            "new could not allocate enough memory");
  }
  memset(array, 0, sizeof(array)); //set all array values as 0

}
Strings::Strings( const char** in_array, int size):count(size){
    
    if( (array = new const char*[ size ] ) == NULL ){
        MMFatalError( "Strings::Strings",
            "new could not allocate enough memory" );
    }
    for(int i=0; i < count; i++ ){
       if( (array[i] = mystrdup( in_array[i] )) == NULL ){
        MMFatalError( "Strings::Strings", 
                    "new could not allocated enough memory" );
       }
    }
   }

const char* Strings::get(int index){
    if( index >= count || index < 0 ){
      MMFatalError( "Strings::get", "Index is out of range!" );
    }
  return array[index];}


