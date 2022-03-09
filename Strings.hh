/*

The strings type is a C++ struct holding an array of a known 
number of char *s. If y is of type strings then y.count is 
the number of elements in the array and y.s[0] through 
y.s[count-1] are the elements of the array.

*/
#ifndef STRINGS_H
#define STRINGS_H   

#include <iostream>

class Strings{
public:
  Strings(int size );
  Strings(const char ** in_array, int size); 
  Strings( void ) : count( 0 ), array( NULL ) {} //   Initialising member variables before the body of the constructor executes

  Strings( Strings& in );            // copy c-tor
  ~Strings( void );                  // d-tor
  Strings& operator= ( Strings& str ); //transmission par reference
  
  const char* get( int index );      // return string at given index
  
  int getCount( void ) const{ return count; }
  
  const char ** getArray( void ){ return array; }

private:
  const char ** array;
  int count;
  
};

#endif