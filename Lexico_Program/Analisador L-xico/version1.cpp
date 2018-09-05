#include <stdio.h>

#define MENOR_IGUAL 2
#define MAIOR_IGUAL 3
#define MENOR       4
#define MAIOR       5
#define IGUAL       6
#define DIFERENTE   7

int next_token() {
  static int la = ' ';
  
  while( la == ' ' )
    la = getchar();
  
  if( la == '<' ) {
    la = getchar();
    
    if( la == '=' ) {
      la = getchar();
      return MENOR_IGUAL; 
    }
    if( la == '>' ) {
      la = getchar();
      return DIFERENTE; 
    }
    
    return MENOR;
  }
  else if( la == '>' ) {
    la = getchar();
    
    if( la == '=' ) {
      la = getchar();
      return MAIOR_IGUAL; 
    }
    
    return MAIOR;
  }
  else if( la == '=' ) {
    la = getchar();
    return IGUAL; 
  }
  
  return EOF;
}

int main( int argc, char* argv[] ) {
  int token;
  
  token = next_token();
  
  while( token != EOF ) { 
    printf( "Lido: %d\n", token );
    token = next_token();
  }
  
  return 0;
}
