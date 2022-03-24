/***********************************************************
* testando RHexlib 
************************************************************/

#include <iostream>
#include "ModuleManager.hpp"
//#include "Strings.hpp"
//#include "SymbolTable.hpp"

using namespace std;

int main()
{
    const char **Tab = new const char* [2];
    Tab[0] = "ola"    ;
    Tab[1] = "Talisma";
    Strings  string;
    
   string = MMGetStrArraySymbol(Tab[1]);

    cout<<string.get(2)<<endl;

return 0;
}

