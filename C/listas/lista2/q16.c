#include <stdio.h>
/*
  Escreva um programa que apresente o somat ́orio de todos os n ́umeros divis ́ıveis por 3 pertencentes ao
  intervalo [0,100] e o somat ́orio de todos os n ́umeros divis ́ıveis por 5 pertencentes ao intervalo ]100,200].
  Obs.: Utilize apenas um la ̧co de repeti ̧c ̃ao.
*/
int main(void) {
  int soma3 = 0, soma5 = 0;
  for (int c = 1 ; c <= 200 ; c++){
    if ((c%3==0)&&(c<=100)){
      soma3 += c;
    }else{
      if ((c%5==0)&&(100<c)&&(c<=200)){
        soma5 += c;
      }
    }
  }
  printf("\nSoma dos divisiveis por 3 em [0, 100]: %i\nSoma dos divisiveis por 5 em ]100, 200]: %i\n", soma3, soma5);


  return 0;
}