/************************************************************************
* Created       : Uluc Saranli, 12/17/1998
* Last Modified : Talisma Mnauel
* Note: 
*
*************************************************************************
* This file is part of RHexLib, 
*
* Copyright (c) 2001 The University of Michigan, its Regents,
* Fellows, Employees and Agents. All rights reserved, and distributed as
* free software under the following license.
************************************************************************/

#ifndef _SYMBOLTABLE_HH
#define _SYMBOLTABLE_HH

#include "Strings.hpp"
#include "Floats.hpp"
#include "Tokenizer.hpp"

// Constants ---
#define MAX_SYMBOL_NAMELEN  128
#define MAX_ARRAY_LENGTH    128

//data types ---
//note: entenda os enum e os struc como forma de criar simples objetos,
//quando declaramos eles como typedef esses objetos passam a ser também tipos de variaveis(objetos) 
typedef enum{ 
  SYMBOL_INVALID, 
  SYMBOL_FLOAT, 
  SYMBOL_STRING
}SymbolType;

typedef enum{
  SCRIPT_FILE   = TOKEN_INPUT_FILE,
  SCRIPT_STRING = TOKEN_INPUT_STRING,
} ScriptType; 

// Symbols class ---
class Symbol{
  private:

    Symbol      *next;
    char         name[MAX_SYMBOL_NAMELEN];
    SymbolType   type;
  
    Floats     *Fvalue;
    Strings    *Svalue;

    friend class SymbolTable;

  public:
    Symbol(void);
   ~Symbol( );

    Symbol &operator= (Symbol &rhs);

    void         setName( const char *n ){ strcpy(name,n);}
    const char  *getName( void ){ return name; }
    SymbolType   getType( void ){ return type; }
    
    void setFarray( float *f, int count );
    void setSarray( const char **s, int count );

    Floats       getFarray( void ){ return *Fvalue;}
    float        getFvalue( unsigned int index){ return Fvalue->get(index); }
    Strings     &getSarray( void ){ return *Svalue; } //retornar a ref do objeto? é szguro?
    const char  *getSvalue( unsigned int index ){ return Svalue->get(index); }
};

class SymbolTable{

public: 
   SymbolTable(void);
  ~SymbolTable();

  Symbol *get( const char *name) ;
  
  Symbol *put( Symbol *sym );
  Symbol *putFloat( const char *name, float val );
  Symbol *putString( const char *name, const char *val);

  void    runScript( ScriptType inputType, const char *file_or_str);
  void    loadFile(const char *filename){ runScript(SCRIPT_FILE, filename);}
  float   readFloat(const char *name, float deflt);
  Floats  readArray(const char *name);
  void    readString(const char *name, char *str, const char *deflt);
  Strings readStrArray(const char *name);
  void    printSymbols(void);

private:
  Symbol *first;
  Symbol *last;
  int     numSymbols;

  //tokenizer object for parsing input files 
  Tokenizer tokenizer;

  bool parse_value( Symbol *sym);
  bool parse_expression( void );
};
#endif