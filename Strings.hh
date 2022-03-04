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
  void printChar(int pos);
private:
  const char ** array;
  int count;
  
};

#endif