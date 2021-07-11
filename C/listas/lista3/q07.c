#include <stdio.h>
#include <string.h>
#define TAM 81
int main(void) {
  char string[TAM];
  char *eInicial=NULL, *eFinal=NULL;
  char temp;
  puts("String inicial: ");
  fgets(string, TAM, stdin);
  // removendo enter
  string[strlen(string)-1] = 0;

  for(int c=0; c<strlen(string)/2;c++){ // conta de 0 a metade do len da string
    eInicial = &string[c];
    eFinal = &string[strlen(string)-1-c];
    temp = * eFinal;
    *eFinal = *eInicial;
    *eInicial = temp;
  }
  printf("string final: %s", string);
  return 0;
}

