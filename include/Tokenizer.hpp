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

#ifndef _TOKENIZER_HH
#define _TOKENIZER_HH

// Standard includes
#include <stdio.h>
#include "MM.hpp"
// Constants -------------------------------------------------------

#define MAX_TOKEN_LENGTH        128

// Input stream types
#define TOKEN_INPUT_UNKNOWN 0
#define TOKEN_INPUT_FILE    1
#define TOKEN_INPUT_STRING  2

// Token type definitions
#define TOKEN_INVALID   0
#define TOKEN_EOF       1  // end-of-input 
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

// The Tokenizer class 
class Tokenizer {

 public:
  Tokenizer( void );
  ~Tokenizer( );

  int  open( int type, const char *file_or_str );
  int  get( Token *token );
  int  eoi( void ); // aka end of input :)
  void close( void );
  
 private:
  int         inputType;

  const char *inputStr;
  FILE*       inputFile;
  char        lastChar;
  int         strPtr;

  int  end_of_input( void );
  //g!b,k( void );
  int  skip_whitespace( void );
  int  get_number_token( Token *token );
  int  get_symbol_token( Token *token );
  int  get_string_token( Token *token );
  int  get_next_char( void );
  void skip_line( void );

};

#define EXPECT_TOKEN(T_IN, TYPE_IN, TOKEN_IN) \
(T_IN).get(TOKEN_IN);  \
  if(((TOKEN_IN)->type)!=(TYPE_IN)) \
  { fprintf ( stderr, "Fatal Error in EXPECT_TOKEN macro: Parse error, invalid token. Aborting!"); \
  return 0;} \

#define GET_TOKEN(T_IN, TOKEN_IN) (T_IN).get(TOKEN_IN)
#endif