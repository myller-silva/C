#include <stdio.h>
/*
  Escreva um programa que leia dois inteiros e ent ̃ao determine e imprima se o primeiro  ́e m ́ultiplo do
  segundo. Obs.: N ̃ao utilizar estrutura de decis ̃ao if.
*/
int main(void) {
  int n1 = 0, n2 = 0;
  printf("Primeiro numero: ");
  scanf("%i", &n1);
  printf("Segundo numero: ");
  scanf("%i", &n2);
  (n1 % n2 == 0) ? printf("%i é multiplo de %i\n", n1, n2) : printf("%i não é multiplo de %i\n", n1, n2);

  return 0;
}