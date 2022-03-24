#include <cstring> //here lives the func strcpy(), 
#include <string.h> //here lives the func strcmp()

#include "ModuleManager.hpp"
#include "Strings.hpp"
#include "Floats.hpp"
#include "SymbolTable.hpp"
//#include "Tokenizer.hpp"

static char * memCpy(const char * in_arr){ //
    
    size_t length = strlen(in_arr)+1;
    char * cpy= new char[length];
    
    if(cpy){memcpy(cpy, in_arr, length);} 
    return cpy;
}
// Symbol Class constructor
Symbol::Symbol(void) {

  name[0] = 0;
  next    = NULL;
  type    = SYMBOL_INVALID;

  Fvalue  = new Floats;
  Svalue  = new Strings;
}
// Symbol Class d-tor
Symbol::~Symbol( ) {

  delete Fvalue;
  delete Svalue;
}
// Symbol overload =
Symbol &Symbol::operator=( Symbol &rhs ) {

  if( this == &rhs ) return *this; // prevent self-assignment

  delete Fvalue;
  delete Svalue;

  Fvalue = new Floats( rhs.Fvalue->getArray(), rhs.Fvalue->getCount() );
  Svalue = new Strings( rhs.Svalue->getArray(), rhs.Svalue->getCount() );

  return *this;
}

void Symbol::setFarray( float *f, int count ) {

  // Delete the old Floats 
   delete Fvalue;

  // Create a new one with the new contents
  Fvalue = new Floats( f, count );

  // Automatically set the type
  type = SYMBOL_FLOAT;
}

void Symbol::setSarray( const char **s, int count ) {

  // Delete the old Strings 
  delete Svalue;

  // Create the new one with the new contents
  Svalue = new Strings( s, count );

  // Automatically set the type
  type   = SYMBOL_STRING;
}

// SymbolTable Class constructor
SymbolTable::SymbolTable(void){

  numSymbols = 0;
  first      = NULL;
  last       = NULL;
}

SymbolTable::~SymbolTable(){

 Symbol *curSymbol, *nextSymbol;

 for( nextSymbol = curSymbol = first; 
      nextSymbol!= NULL; 
      curSymbol  = nextSymbol){

        nextSymbol = curSymbol->next;
        delete curSymbol;
 } 
 first = NULL;
 last  = NULL;
}
// searches for a named Symbol
 Symbol *SymbolTable::get( const char *name){

   Symbol *curSymbol;

   for( curSymbol=first; 
        curSymbol!=NULL;
        curSymbol = curSymbol->next
        ){
          if(strcmp(name, curSymbol->name)==0){//compares two strings character by character. If equals return 0
            return curSymbol;
          }
        }

        //else
        return NULL;
 } 
 // Inserts a Symbol entry to the table
Symbol *SymbolTable::put(Symbol *sym){

  if( last == NULL){
    first = last = sym;
  } else{
    last->next = sym;
    sym->next  = NULL;
    last=sym;
  }
  numSymbols++;

  return sym;
}
// Creates and inserts a number Symbol entry to the table
Symbol *SymbolTable::putFloat( const char *name, float val ){

  Symbol *sym;

  if((sym = new Symbol())==NULL){
    return NULL;
  }
  sym->setName( name );
  sym->setFarray( &val, 1 );

  return put( sym );
}
// Creates and inserts a string symbol entry to the table
Symbol *SymbolTable::putString( const char *name, const char *val ) {

  Symbol *sym;

  if ( ( sym = new Symbol() ) == NULL )
    return NULL;

  sym->setName( name );
  sym->setSarray( &val, 1 );

  return put( sym );
}
// Reads in and adds symbol definitions from a file
void SymbolTable::runScript(ScriptType inputType, const char *file_or_str){

  int errno;

  // start the tokenizer
  if((errno = tokenizer.open(inputType, file_or_str))<0){
      MMWarning( "SymbolTable::runScript", "Error opening script file!" );
    return; //get out 
  }
  // read and add all symbol definitions
  while( parse_expression() );

  //close tokenizer
  tokenizer.close();
} 
// Reads a float parameter. If not found, returns the supplied default value.
float SymbolTable::readFloat( const char *name, float deflt ) {
  Symbol    *sym;

  if ( ( sym = get( name ) ) != NULL && sym->getType() == SYMBOL_FLOAT )
    return sym->getFvalue( 0 );
  else
    return deflt;
}
// Reads a string parameter. If not found, returns the supplied default value.
void SymbolTable::readString(const char * name, char * str, const char * deflt) {
  
  Symbol    *sym;

  if ( ( sym = get( name ) ) != NULL && sym->getType() == SYMBOL_STRING ) {
    strcpy( str, sym->getSvalue( 0 ) );
   // return;

  } else {
    strcpy( str, deflt );
   // return;
  }
}

// Reads a string array parameter. If not found, returns an 
// empty strings struct.
Strings &SymbolTable::readStrArray( const char *name ){

  Symbol *sym;
  static Strings deflt;

  if ( ( sym = get( name ) ) != NULL && sym->getType() == SYMBOL_STRING ){
    return sym->getSarray();
  }else{ 
    return deflt;
  }
}

// Prints the current symbols and their values to stdout. 
// for debugging purposes only.
void SymbolTable::printSymbols( void ) {

  Symbol * sym = first;
  Floats   fvalue;
  Strings  svalue;
  int      i;

  while ( sym ) {
    
    if ( sym->getType() == SYMBOL_FLOAT ) {

      fvalue = sym->getFarray();
      printf( "\nName  : %s\n", sym->getName() );
      printf( "Value : " );

      if ( fvalue.getCount() != 1 )
        printf( "{" );
      for ( i = 0; i < fvalue.getCount(); i++ )
        printf( "%e ", fvalue.get(i) );
      if ( fvalue.getCount() != 1 )
        printf( "}\n" );
      else
        printf( "\n" );

    } else if ( sym->getType() == SYMBOL_STRING ) {

      svalue = sym->getSarray();
      printf( "\nName  : %s\n", sym->getName() );
      printf( "Value : " );

      if ( svalue.getCount() != 1 )
        printf( "{" );
      for ( i = 0; i < svalue.getCount(); i++ )
        printf( "\"%s\" ", svalue.get(i) );
      if ( svalue.getCount() != 1 )
        printf( "}\n" );
      else
        printf( "\n" );
    }

    sym = sym->next;
  }
}

bool SymbolTable::parse_value( Symbol *sym){
  Token token;
  float fvalue;
  float farray[MAX_ARRAY_LENGTH];
  
  const char **sarray=new const char*[MAX_ARRAY_LENGTH];
  const char *svalue;
  int        count; 

  /* 
  The possible values for symbols are:
      String : TOKEN_STRING
      Number : TOKEN_FLOAT | TOKEN_INTEGER
      Float Array : "{" ( ( TOKEN_FLOAT | TOKEN_INTEGER ) "," )... "}"
      String Array : "{" ( ( TOKEN_STRING | TOKEN_STRING ) "," )... "}"
  */
  if ( token.type == TOKEN_FLOAT ) {
    // Acquire a floating point value for the symbol
    fvalue = token.fvalue;
    sym->setFarray( &fvalue, 1 );

  } else if ( token.type == TOKEN_INTEGER ) {
    // Acquire an integer value for the symbol

    fvalue = token.ivalue;
    sym->setFarray( &fvalue, 1 );

  } else if ( token.type == TOKEN_STRING ) {
    // Acquire a string value for the symbol

    svalue = token.svalue;
    sym->setSarray( &svalue, 1 );

  } else if ( token.type == TOKEN_LBRACKET ) {
    // The value is an array of numbers.
    count = 0;

    GET_TOKEN( tokenizer, &token );

    if ( token.type == TOKEN_FLOAT || token.type == TOKEN_INTEGER ) {
      // This must be a float array. Proceed accordingly

      // Get all the numbers in the array
      while ( token.type != TOKEN_RBRACKET ) {

        if ( token.type == TOKEN_FLOAT ) {
          // Acquire a floating point value for the symbol
          farray[count++] = token.fvalue;

        } else if ( token.type == TOKEN_INTEGER ) {
          // Acquire an integer value for the symbol
          farray[count++] = token.ivalue;

        } else {
          // Oops, unexpected token here
          MMWarning("SymbolTable::parse_value", "Invalid array element!" );
          return false;
        }
        GET_TOKEN( tokenizer, &token );
      }
      // Set the symbol value to the array
      sym->setFarray( farray, count );

    } else if ( token.type == TOKEN_STRING ) {
      // This is a string array. Proceed accordingly.

      // Get all the strings in the array
      while ( token.type != TOKEN_RBRACKET ) {

        if ( token.type == TOKEN_STRING ) {
          // Acquire string value for the symbol
          
          sarray[count] = new char[ strlen( token.svalue ) + 1 ];
          strcpy( memCpy(sarray[ count ]), token.svalue );
          count++;

        } else {
          // Oops, unexpected token here
          MMWarning("SymbolTable::parse_value", "Invalid array element!" );
          return false;
        }
        GET_TOKEN( tokenizer, &token );
      }

      // Set the symbol value to the array
      
      sym->setSarray( sarray, count );

    } else {

      // Unexpected token type.
      MMWarning("SymbolTable::parse_value", "Invalid array element!" );
      return false;

    }


  } else {
    // Oops, unexpected token here
    MMWarning("SymbolTable::parse_value", "Invalid value assignment!" );

    return false;
  }
  
  return true;
}

bool SymbolTable::parse_expression( void ) {

  Symbol *sym, *oldSymbol;
  Token  token;

  // First look for the symbol name
  GET_TOKEN( tokenizer, &token );
  
  if ( token.type == TOKEN_EOF )
    return false;

  if ( token.type != TOKEN_SYMBOL ) {
    MMWarning( "SymbolTable::parse_expression", 
               "Symbol token expected. Aborting!" );
    return false;
  }

  // If the symbol already exists, retrieve it. Otherwise, create a new one
  if ( ( oldSymbol = get( token.svalue ) ) != NULL ) {

    sym = oldSymbol;

  } else {

    sym = new Symbol;
  }

  // Set the name of the symbol
  sym->setName( token.svalue );

  // Expect an equal sign
  EXPECT_TOKEN( tokenizer, TOKEN_EQUAL, &token );

  // Parse the value and fill in the symbol entry
  if ( ! parse_value( sym ) ) {
    if ( sym != oldSymbol )
      delete sym;

    return false;
  }

  // Insert the table entry
  if ( sym != oldSymbol )
    put( sym );

  // Expect a semicolon at the end
  EXPECT_TOKEN( tokenizer, TOKEN_SEMICOLON, &token );

  return true;
}
