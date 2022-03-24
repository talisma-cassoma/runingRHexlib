/************************************************************************
* Created       : Uluc Saranli, 12/17/1998
* Last Modified : Talisma Manuel
* 
* Note: the Tokenizer parse an input stream(strings or floats values) 
*       into to a stream of tokens, which are then interpreted by a 
*       higher level parser.
*************************************************************************
* This file is part of RHexLib, 
*
* Copyright (c) 2001 The University of Michigan, its Regents,
* Fellows, Employees and Agents. All rights reserved, and distributed as
* free software under the following license.
************************************************************************/

#ifndef _TOKENIZER_HH
#define _TOKENIZER_HH

// Standard includes
#include <stdio.h>

// Constants -------------------------------------------------------

#define MAX_TOKEN_LENGTH        128

// Input stream types
#define TOKEN_INPUT_UNKNOWN 0
#define TOKEN_INPUT_FILE    1
#define TOKEN_INPUT_STRING  2

// Token type definitions
#define TOKEN_INVALID   0
#define TOKEN_EOF       1
#define TOKEN_INTEGER   2
#define TOKEN_FLOAT     3
#define TOKEN_STRING    4
#define TOKEN_SYMBOL    5
#define TOKEN_EQUAL     6   // =
#define TOKEN_SEMICOLON 7   // ;
#define TOKEN_POUND     8   // #
#define TOKEN_LBRACKET  9   // {
#define TOKEN_RBRACKET  10  // }

#define NO_ERROR 0
#define TOKENIZER_ERROR -1

// Data types -----------------------------------------------------

typedef struct {
  int   type;
  
  int   ivalue;
  float fvalue;
  char  svalue[MAX_TOKEN_LENGTH];
} Token;

// The Tokenizer class ---------------------------------------------
class Tokenizer {

 public:
  Tokenizer( void );
  ~Tokenizer( );

  int open( int type, const char *file_or_str );
  int get( Token *token );
  void close( void );
  int eoi( void );
  
 private:
  int        inputType;

  FILE*      inputFile;
  const char *inputStr;
  int        strPtr;

  char       lastChar;

  int end_of_input( void );
  int get_next_char( void );
  int skip_whitespace( void );
  int get_number_token( Token *token );
  int get_symbol_token( Token *token );
  int get_string_token( Token *token );
  void skip_line( void );

};

#define EXPECT_TOKEN( T_IN, TYPE_IN, TOKEN_IN )           \
  ( T_IN ).get( ( TOKEN_IN ) );                           \
  if ( ( TOKEN_IN )->type != ( TYPE_IN ) ) {              \
    MMWarning( "EXPECT_TOKEN macro",                      \
               "Parse error, invalid token. Aborting!" ); \
    return false;                                         \
  }

#define GET_TOKEN(T_IN, TOKEN_IN) (T_IN).get(TOKEN_IN)

#endif
