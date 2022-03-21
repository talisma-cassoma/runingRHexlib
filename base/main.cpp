/******************************************************************************
testando RHexlib 
*******************************************************************************/
#include <iostream>
//#include "Strings.hpp"
//#include "Floats.hpp"
#include "SymbolTable.hpp"

using namespace std;

int main()
{
    
    const char ** arr = new const char * [3];
    arr[0]= "Talisma";
    arr[1]= "geovna";
    arr[2]= "Yachane Alexandre";
    
    /*
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
    texto.set("youtubeKids", 2);
    cout<<texto.get(2)<<endl;
    */
SymbolTable *table_S= new SymbolTable();//allocate in memory
Symbol      *simbolo = new Symbol();//allocate in memory

float *f = new float[4]; for(int i=0; i<3; i++){f[i]=i*rand();}

simbolo->setFarray(f,4);
simbolo=table_S->putFloat("tres", 4.2); for(int i=0; i<4; i++) cout<<"simbolo: "<<simbolo->getFvalue(i)<<endl;

return 0;
}

