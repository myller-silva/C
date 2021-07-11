#include<stdio.h>
#include<string.h>
// Fa ̧ca um programa em C que leia uma string e um caracter do usu ́ario e informe se a string de
// entrada cont ́em o caracter fornecido.
#define TAM 80
int main(){  
  char *pS = NULL;
  char string[TAM];
  char c;
  int existe=0;
  pS = string;
  puts("Digite uma string: ");
  fgets(pS, TAM-1, stdin);
  puts("Digite um caractere: ");
  scanf("%c", &c);
  // corrigir o bug do enter:
  *(pS + strlen(pS)-1)= 0; // pS[strlen(pS)-1] = 0;
  // varrendo a string:
  for(int k=0; k<strlen(string); k++){
    if(c==*(pS+k)){
      existe=1;
      break;
    }
  }
  existe ? printf("O caractere '%c' está na string '%s'", c, pS):
  printf("O caractere '%c' NÃO está na string '%s'\n", c, pS);
  return 0;
}