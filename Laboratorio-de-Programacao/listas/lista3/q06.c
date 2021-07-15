#include <stdio.h>
#include<string.h>
// Fa ̧ca um programa em C que concatene duas strings recebidas pelo usu ́ario. Construa uma vers ̃ao
// com uso da fun ̧c ̃ao com strcat() e outra sem.
#define TAM 80 

int main(void) {
  char string1[TAM], string2[TAM];
  char *pS1=NULL;

  puts("Digite a primeira string: ");
  fgets(string1, TAM, stdin);
  puts("Digite a segunda string: ");
  fgets(string2, TAM, stdin);
  //remover o enter:
  string1[strlen(string1)-1] = 0;
  string2[strlen(string2)-1] = 0;
  pS1 = string1; 
  // concatenar
  for(long unsigned c=0;c<strlen(string2); c++){
    *(pS1+strlen(string1)) = *(string2+c); // pS1[strlen(string1)] = string2[c];
  }
  printf("\nConcatenado: %s", pS1);  
  return 0;
}