#include <stdio.h>

#ifndef _FLOATS_HH
#define _FLOATS_HH


class Floats {
public:
  Floats( int in_count );            // c-tors, d-tors
  Floats( float* in_array, int size );
  Floats( void ) : count( 0 ), array( NULL ) {}
  
  Floats( const Floats& in );
  ~Floats( void );

  Floats& operator=( const Floats& rhs ); // overloaded operators

  float get( int index ) const;      // returns float at index
  void set( int index, float f );    // sets the value at index

  int getCount( void ) const { return count; }
  float *getArray( void ) const	{ return array; }

private:
  int          count;                // number of elements
  float*       array;

};// end of Floats class declaration------------------------------------------

#endif
