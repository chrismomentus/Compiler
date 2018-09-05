#include <stdio.h>

enum TOKEN { MENOR_IGUAL = 256, MAIOR_IGUAL, DIFERENTE, ID, NUM };

int next_token() {
  static int la = ' ';
  
  // Desconsiderar espaços em branco.
  while( la == ' ' )
    la = getchar();
  
  if( (la >= 'a' && la <= 'z') || (la >= 'A' && la <= 'Z') || la == '_' ) {
    la = getchar();
    while( (la >= 'a' && la <= 'z') || (la >= 'A' && la <= 'Z') || la == '_' ||
      (la >= '0' && la <= '9') ) {
      la = getchar();
    }
    
    return ID;
  }
  else if( (la >= '0' && la <= '9') ) {
    la = getchar();
    while( (la >= '0' && la <= '9') ) 
      la = getchar();
    
    return NUM;
  }
  else switch( la ) {
    case '<': {
      la = getchar();
    
      if( la == '=' ) {
        la = getchar();
        return MENOR_IGUAL; 
      }
    
      if( la == '>' ) {
        la = getchar();
        return DIFERENTE; 
      }
    
      return '<';
    }
    
    case '>': {
      la = getchar();
    
      if( la == '=' ) {
        la = getchar();
        return MAIOR_IGUAL; 
      }
    
      return '>';
    }
  
    case '=' : {
      la = getchar();
      return '=';
    }
    case '+' : {
      la = getchar();
      return '+';
    }
    case '-' : {
      la = getchar();
      return '-';
    }
    case '*' : {
      la = getchar();
      return '*';
    }
    case '/' : {
      la = getchar();
      return '/';
    }
    case '(' : {
      la = getchar();
      return '(';
    }
    case ')' : {
      la = getchar();
      return ')';
    }
  }
  
  return EOF;
}

int main( int argc, char* argv[] ) {
  int token;
  
  while( (token = next_token()) != EOF ) 
    printf( "Lido: %d\n", token );
  
  return 0;
}
