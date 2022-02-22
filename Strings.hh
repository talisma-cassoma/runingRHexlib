
#ifndef _STRINGS_HH
#define _STRINGS_HH

#include <stdio.h>

class Strings{
public:
  Strings(int in_count);
  Strings( const char** in_array, int size );
  int getCount(void){return count;} 
  const char* get(int index);

private:
  int count;
  const char** array; 
};

#endif