#include <stdio.h>
#include "ModuleManagerMessages.hh"

void MMFatalError( const char *fn, const char *msg )  { 
 fprintf ( stderr, "Fatal Error in %s: %s\n", fn, msg );
    }
void MMWarning( const char *fn, const char *msg ) { 
     fprintf( stderr, "Warning in %s: %s\n", fn, msg ); 
    }	