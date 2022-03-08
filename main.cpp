/******************************************************************************
testando RHexlib 
*******************************************************************************/
#include <iostream>
#include "Strings.hh"
#include "MM.hh"
using namespace std;

int main()
{
    const char ** arr = new const char * [5];
    arr[0]= "Talisma";
    arr[1]= "geovna";
    arr[2]= "Yachne";
    Strings texto( arr, 5);
    texto.printChar(2);

    return 0;
}