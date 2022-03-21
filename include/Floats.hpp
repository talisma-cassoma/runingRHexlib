/************************************************************************
* Created       : Laura McWilliams, 06/29/2001
* Last Modified : Talisma Mnauel
* Note: The floats type is a C++ struct holding an array of a known 
*       number of floats. If x is of type floats then x.count is the 
*       number of elements in the array and x.f[0] through x.f[count-1] 
*       are the elements of the array.
*************************************************************************
* This file is part of RHexLib, 
*
* Copyright (c) 2001 The University of Michigan, its Regents,
* Fellows, Employees and Agents. All rights reserved, and distributed as
* free software under the following license.
************************************************************************/
#include <stdio.h>

#ifndef _FLOATS_HH
#define _FLOATS_HH


class Floats {
public:
  Floats( int in_count );            // c-tors, d-tors
  Floats( float *in_array, int size );
  Floats( void ) : count( 0 ), array( NULL ) {}
  
  Floats( const Floats &in );
  ~Floats( void );

  Floats &operator=( const Floats &rhs ); // overloaded operators

  float get( int index ) const;      // returns float at index
  void set( int index, float f );    // sets the value at index

  int getCount( void ) const { return count; }
  float* getArray( void ) const	{ return array; }

private:
  int          count;                // number of elements
  float*       array;

};// end of Floats class declaration------------------------------------------

#endif
