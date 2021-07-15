#include <stdio.h>
// Fa ̧ca um programa em C que leia uma string do usu ́ario e informe a quantidade de caracteres da
// string fornecida. N ̃ao use a fun ̧c ̃ao strlen().
#define TAM 80

int main(){
  char string[TAM];
  char *pS;
  pS = &string[0];
  int cont_c = 0;
  // lendo a string:
  puts("Digite uma string: ");
  fgets(string, TAM, stdin);
  // contando os caracteres:
  while(*(pS + cont_c)!='\0'){
    cont_c++;
  }  
  *(string+cont_c-1) = 0; //string[(cont_c)-1] = 0; //corrigindo bug do enter
  cont_c--; //retirando o enter da contagem  
  printf("Quantidade de caracteres: %d", cont_c);
  return 0;
}