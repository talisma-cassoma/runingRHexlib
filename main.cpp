/******************************************************************************
testando RHexlib 
*******************************************************************************/
#include <iostream>
#include "Strings.hh"
#include "MM.hh"
using namespace std;

int main()
{
    const char ** arr = new const char * [3];
    arr[0]= "Talisma";
    arr[1]= "geovna";
    arr[2]= "Yachne";
    
    const char ** arr2 = new const char * [3];
    arr2[0]= "pipoca nanquim";
    arr2[1]= "rocketseat";
    arr2[2]= "PGD";
    
    Strings texto( arr, 3);
    Strings palavras(arr2,3);
    
    //texto.~Strings(); //calling d-tor
    cout<<palavras.get(0)<<endl;
    
    palavras = texto;
    
    cout<<palavras.get(0)<<endl;
    texto.set("youtube", 2);
    cout<<texto.get(2)<<endl;

    return 0;
}