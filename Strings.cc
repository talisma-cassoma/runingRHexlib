#include <iostream> //contem as func memset(), memcopy() ... etc

#include "Strings.hh"
#include "MM.hh"

using namespace std;

Strings::Strings(int size):count(size){

    array = new const char * [count];
    array[0] = "helo fellas";
    array[1] = "hi";
   // MMFatalError( "Strings::Strings","new could not allocate enough memory" );
   }
void Strings::printChar(int pos){
    cout<<array[pos]<<endl;
}


