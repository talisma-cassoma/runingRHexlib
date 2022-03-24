#ifndef ModuleManager_HPP
#define ModuleManager_HPP

#include <stdio.h> //fprint()
#include <iostream>
//#include "ModuleManager.hpp"
#include "Strings.hpp"
//#include "SymbolTable.hpp"

using namespace std;
 Strings &MMGetStrArraySymbol( const char *n ) { 
  
  const char** Tab_ = new const char*[3];
  Tab_[0] = n;
  Tab_[1] = "tens carro?";
  Tab_[2] = "tens BICICLETA?";

  //Symbol *sym;
  
 static Strings deflt(Tab_, 3);
  
  Strings  *Svalue;

  if(deflt.getCount() == 2){
    return deflt;
  }
  else{
    cout<<"1: nao houve alocacao de memoria"<<endl;
    
    return *Svalue;
  }
  //}
}

 
 inline void MMFatalError( const char *fn, const char *msg )  { 
 fprintf ( stderr, "Fatal Error in %s: %s\n", fn, msg );
    }
 inline void MMWarning( const char *fn, const char *msg ) { 
     fprintf( stderr, "Warning in %s: %s\n", fn, msg ); 
    }
#endif	