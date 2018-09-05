#include <stdio.h>

enum TOKEN { MENOR_IGUAL = 256, MAIOR_IGUAL, DIFERENTE, ID, NUM };

const int MAX_ID = 1023;
char lexema[1024];

int is_digit( int ch ) {
  return ch >= '0' && ch <= '9';
}

int is_alpha( int ch ) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

int is_alnum( int ch ) {
  return is_alpha( ch ) || is_digit( ch );
}

int is_space( int ch ) {
  return ch == ' ' || ch == '\n' || ch == '\t';
}

int next_token() {
  static int la = ' ';
  int posicao = 0;
  
  // Desconsiderar espaços em branco.
  while( is_space( la ) )
    la = getchar();
  
  if( is_alpha( la ) ) {
    lexema[posicao++] = la;
    la = getchar();
    
    while( is_alnum( la ) ) {
      lexema[posicao++] = la;
      la = getchar();
    }
    
    lexema[posicao] = '\0';
    return ID;
  }
  else if( is_digit( la ) ) {
    lexema[posicao++] = la;
    la = getchar();
    while( is_digit( la ) ) {
      lexema[posicao++] = la;
      la = getchar();
    }

    lexema[posicao] = '\0';
    return NUM;
  }
  else switch( la ) {
    case '<': {
      lexema[posicao++] = la;
      la = getchar();
    
      if( la == '=' ) {
        lexema[posicao++] = la;
        la = getchar();
        lexema[posicao] = '\0';
        return MENOR_IGUAL; 
      }
    
      if( la == '>' ) {
        lexema[posicao++] = la;
        la = getchar();
        lexema[posicao] = '\0';
        return DIFERENTE; 
      }
    
      lexema[posicao] = '\0';
      return '<';
    }
    
    case '>': {
      lexema[posicao++] = la;
      la = getchar();
    
      if( la == '=' ) {
        lexema[posicao++] = la;
        la = getchar();
        lexema[posicao] = '\0';
        return MAIOR_IGUAL; 
      }
    
      lexema[posicao] = '\0';
      return '>';
    }
  
    case '=' : {
      lexema[posicao++] = la;
      la = getchar();
      lexema[posicao] = '\0';
      return '=';
    }
    case '+' : {
      lexema[posicao++] = la;
      la = getchar();
      lexema[posicao] = '\0';
      return '+';
    }
    case '-' : {
      lexema[posicao++] = la;
      la = getchar();
      lexema[posicao] = '\0';
      return '-';
    }
    case '*' : {
      lexema[posicao++] = la;
      la = getchar();
      lexema[posicao] = '\0';
      return '*';
    }
    case '/' : {
      lexema[posicao++] = la;
      la = getchar();
      lexema[posicao] = '\0';
      return '/';
    }
    case '(' : {
      lexema[posicao++] = la;
      la = getchar();
      lexema[posicao] = '\0';
      return '(';
    }
    case ')' : {
      lexema[posicao++] = la;
      la = getchar();
      lexema[posicao] = '\0';
      return ')';
    }
  }
  
  return EOF;
}

int main( int argc, char* argv[] ) {
  int token;
  
  while( (token = next_token()) != EOF ) 
    printf( "Lido: %d [%s]\n", token, lexema );
  
  return 0;
}
