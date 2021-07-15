#include <stdio.h>
/*
  Construir um programa que apresente como resultado o fatorial dos valores  ́ımpares situados na faixa
  n ́umero de 1 a 10.
*/

int main(void) {
  for(int n = 0 ; n < 10 ; n++){
    if (n%2!=0){
      int fat = n;
      int mult = 1;
      printf("%i! = ", fat);
      while (fat>0){
        mult *= fat;
        printf("%i", fat);
        fat--;
        ((fat>0)&&(n!=1)) ? printf(" x ") : ((fat==0)&&(n!=1)) ? printf(" = %i", mult) :-1;
      }
    }
    printf("\n");
  }
  return 0;
}