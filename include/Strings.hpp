/************************************************************************
* Created       : Uluc Saranli, 11/16/2000
* Last Modified : Talisma Manuel
* Note: The strings type is a C++ struct holding an array of a known 
*       number of char *s. If y is of type strings then y.count is 
*       the number of elements in the array and y.s[0] through 
*       y.s[count-1] are the elements of the array.
*************************************************************************
* This file is part of RHexLib, 
*
* Copyright (c) 2001 The University of Michigan, its Regents,
* Fellows, Employees and Agents. All rights reserved, and distributed as
* free software under the following license.
************************************************************************/

#ifndef STRINGS_HPP
#define STRINGS_HPP   

#include <iostream> //here lives the func memcpy() ... 

class Strings{
public:
  Strings(int size );
  Strings(const char ** in_array, int size); 
  Strings( void ) : count( 0 ), array( NULL ) {} //   Initialising member variables before the body of the constructor executes

  Strings( Strings& in );            // copy c-tor
  ~Strings( void );                  // d-tor
  Strings &operator= ( Strings& str ); //transmission par reference
  
  const char *get( int index );      // return string at given index
  void        set(const char * str, int index ); // set string at index
  int         getCount( void ) const{ return count; }
  
  const char **getArray( void ){ return array; }

private:
  const char **array;
  int          count;
  
};

#endif