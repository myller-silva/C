#include <stdio.h>
/*
  Escreva um programa que receba um n ́umero inteiro e ent ̃ao determine e imprima se ele  ́e par ou  ́ımpar.
  Obs.: N ̃ao utilizar estrutura de decis ̃ao if.
*/
int main(void) {
  int n = 0;
  printf("Digite um numero: ");
  scanf("%i", &n);
  printf("O numero %i é: ", n);
  n % 2 == 0 ? printf("Par\n") : printf("Impar\n");
  return 0;
}