#include <stdio.h>
#include <string.h>
// Fa ̧ca um programa em C que leia duas strings do usu ́ario e informe se elas s ̃ao iguais. Fa ̧ca uma
// vers ̃ao com o uso da fun ̧c ̃ao strcmp() e outra sem.
#define TAM 80
int main(){
  char string1[TAM], string2[TAM];
  char *pS1=NULL, *pS2=NULL;
  pS1 = &string1[0];
  pS2 = string2;
  int diferente = 0;

  puts("Digite a primeira string: ");
  fgets(pS1, TAM, stdin);
  puts("Digite a segunda string: ");
  fgets(pS2, TAM, stdin);
  // verificar se têm o mesmo tamanho
  if(strlen(pS1)!=strlen(pS2)){
    diferente = 1;
  }else{
    // verificar se os caracteres são iguais
    for(int c=0; c<strlen(pS1); c++){
      if(*(pS1+c)!=pS2[c]){ // pS2[c] é o mesmo que *(pS2+c)
        printf("%c é diferente de %c", *(pS1+c), *(pS2+c));
        diferente = 1;
        break;
      }
    }
  }
  diferente?puts("\nAs strings são diferentes."):
  puts("\nAs strings são iguais.");  
  return 0;
}