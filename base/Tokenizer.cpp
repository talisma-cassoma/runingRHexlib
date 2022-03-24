#include <ctype.h> //contem isdigit(), isspace() e isalpha()
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(void){

    inputType = TOKEN_INPUT_UNKNOWN;
    inputFile = NULL;
    inputStr  = NULL;
    strPtr    = 0;
    lastChar  = 0;
}

//Tokenizer::~Tokenizer : Class destructor
Tokenizer::~Tokenizer(void){
    close(); //vai ser definido mais tarde 
}

// Initializes the tokenizer with the specified input type
int Tokenizer::open(int type, const char *file_or_str ){
    
    if(type==TOKEN_INPUT_FILE){//se o tipo for do tipo FILE
        //retornar um error se nao conseguir abrir a file
        if((inputFile = fopen( file_or_str, "r"))==NULL){
            return TOKENIZER_ERROR;
        }
        //se tiver o ficheiro entao: 
        inputType = TOKEN_INPUT_FILE;
    }else if(type == TOKEN_INPUT_STRING){//se o tipo for do tipo STRING
    
    inputType = TOKEN_INPUT_STRING;
    inputStr = file_or_str;  //a string passada no argumento

    }else{//se nao for nenhuma das opcoes acima entao 
        return TOKENIZER_ERROR;
    }
    return get_next_char();
}
int Tokenizer::get( Token *token){
    int errno;

  while (1) {
    if ( ( errno = skip_whitespace() ) < 0 )
      return errno;

    if ( isdigit( lastChar ) || lastChar == '-' || lastChar == '.') {
      // Number token
      return get_number_token( token );
      
    } else if ( isalpha(lastChar) ) {
      // Symbol or keyword token
      return get_symbol_token( token );

    } else if ( lastChar == '\"' ) {
      // String token
      return get_string_token( token );

    } else if ( lastChar == '=' ) {

      token->type = TOKEN_EQUAL;

      return get_next_char();

    } else if ( lastChar == ';' ) {

      token->type = TOKEN_SEMICOLON;

      return get_next_char();

    } else if ( lastChar == '{' ) {

      token->type = TOKEN_LBRACKET;

      return get_next_char();

    } else if ( lastChar == '}' ) {

      token->type = TOKEN_RBRACKET;

      return get_next_char();

    } else if ( lastChar == '#' ) {

      skip_line();

    } else if ( end_of_input() ) {

      token->type = TOKEN_EOF;

      return get_next_char();

    } else {
      // Unknown token
      token->type = TOKEN_INVALID;
      
      return NO_ERROR;
    }
  }
}
void Tokenizer::close(void){
    if(inputType == TOKEN_INPUT_FILE){//fechar o ficheiro se estiver aberto
        if(inputFile != NULL){
            fclose(inputFile);
        }
        inputFile = NULL;
    }else{
        inputStr = NULL;
        strPtr = 0;
    }
}

// Tokenizer::eoi : Checks the end of input
int Tokenizer::eoi( void ) {//acho esse metodo desnecessario
    return end_of_input();
}

int Tokenizer::end_of_input(void){
    if(inputType == TOKEN_INPUT_FILE){
            return feof( inputFile ); //retorna 1 ou 0 se chegou ao fim do ficheiro  
    }else{
        return (lastChar == 0);
    }
}
// Tokenizer::get_next_char : Retrieves the next character from the input stream
int Tokenizer::get_next_char(void){
    
    if( inputType == TOKEN_INPUT_FILE){
        //input type: file
        lastChar = fgetc(inputFile); //pega um so caracter do ficheiro
    }else{
        //input type: string
        lastChar = inputStr[strPtr]; //obs que o elemento inputStr[do length size da string]= 0
        //lastChar é un string ou seja um tableu de char 
        if(lastChar != 0){
            strPtr++;
        }
    }
    return NO_ERROR; 
}

//Skips all the whitespace following the current input position 
int Tokenizer::skip_whitespace(void){
    int errno;

    while(isspace(lastChar) && !end_of_input()){
        if((errno = get_next_char() )<0){
            return errno;
            }
    }
    return NO_ERROR;
}

//Retrieves a number token from the input
int Tokenizer::get_number_token( Token *token ) {

    char str[MAX_TOKEN_LENGTH];
    int strP = 0;
    bool isfloat= false;
    int errno;

    while( lastChar =='.' || lastChar == 'e'
        || lastChar =='-' || isdigit(lastChar)){
        
        str[ strP++] = lastChar;

        if( lastChar =='.' || lastChar == 'e'|| lastChar =='-' ){ isfloat = true; }
        
        if( (errno= get_next_char()) < 0 ){return errno;}
    }
    str[strP] = 0;
   if(isfloat){
        if( sscanf( str, "%f", &token->fvalue) == 0 ){
        token->type = TOKEN_INVALID;
        }else{
            token->type = TOKEN_INVALID;
        }
   }else{
       token->type = TOKEN_INTEGER;
   }
   return NO_ERROR;
}

//Retrieves a symbol token from the input
int Tokenizer::get_symbol_token( Token *token ) {

  int   strP = 0;
  int   errno;

  if ( !isalpha( lastChar ) && lastChar != '_' ) {

    token->type = TOKEN_INVALID;
    return NO_ERROR;
  }

  while ( !isspace( lastChar ) ) {
    token->svalue[ strP++ ] = lastChar;

    if ( !isalpha( lastChar ) && !isdigit( lastChar ) && lastChar != '_') {

      token->type = TOKEN_INVALID;
      return NO_ERROR;
    }

    if ( ( errno = get_next_char() ) < 0 )
      return errno;
  }

  token->svalue[ strP ] = 0;
  token->type = TOKEN_SYMBOL;

  return NO_ERROR;
}

//Retrieves a string token from the input
int Tokenizer::get_string_token( Token *token ) {

  int   strP = 0;
  int   errno;
  
  // Skip the opening quote
  if ( ( errno = get_next_char() ) < 0 )
    return errno;

  while ( lastChar != '\"' ) {
    token->svalue[ strP++ ] = lastChar;

    if ( ( errno = get_next_char() ) < 0 )
      return errno;
  }

  // Skip the closing quote
  if ( ( errno = get_next_char() ) < 0 )
    return errno;

  token->svalue[ strP ] = 0;
  token->type = TOKEN_STRING;

  return NO_ERROR;
}

//Skips the current line from the input stream
void Tokenizer::skip_line( void ) {

  while ( lastChar != '\n' && !end_of_input( ) )
    get_next_char();
}