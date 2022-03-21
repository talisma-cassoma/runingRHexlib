#include "Floats.hpp"
#include "MM.hpp"

// implementations for Floats class

// c-tor w/ count as parameter
Floats::Floats( int in_count ) : count( in_count ){
  if( ( array = new float[ in_count ] ) == NULL )
    MMFatalError( "Floats::Floats", "new could not allocate enough memory" );
}


// c-tor with array of floats as parameter
Floats::Floats( float *in_array, int size ) : count( size ){
  int i;
  
  if( ( array = new float[ size ] ) == NULL )
    MMFatalError( "Floats::Floats", "new could not allocate enough memory" );

  for( i = 0; i < count; i++ )
    array[i] = in_array[i];
}


// copy c-tor
Floats::Floats( const Floats& in ){
  count = in.getCount();
  int i;

  if( ( array = new float[ count ] ) == NULL )
    MMFatalError( "Floats::Floats", "new could not allocate enough memory" );
  
  for( i = 0; i < count; i++ )
    array[i] = in.get(i);
}//---------------------------------------------------------------------------


// d-tor----------------------
Floats::~Floats( void ){
  if( array ) delete[] array;
}


// assignment operator-----------------------------------------------------
Floats& Floats::operator=( const Floats& rhs ){
  if( this == &rhs ) return *this;    // avoid self-assignment
  int i;

  if( array ) delete[] array;
  
  count = rhs.getCount();
  if( (array = new float[ count ]) == NULL )
    MMFatalError( "Floats::operator=", "new could not allocate memory" );
  
  for( i = 0; i < count; i++ )
    array[i] = rhs.get(i);
  return *this;
}


// get function-------------------------------------------
float Floats::get( int index ) const{
  if( index >= count || index < 0 )
    MMFatalError( "Floats::get", "Index out of range!" );
  return array[ index ];
}

void Floats::set( int index, float f ){
  if( index >= count || index < 0 )
    MMFatalError( "Floats::set", "Index out of range!" );
  array[index] = f;
}//-------------------------------------------------------






