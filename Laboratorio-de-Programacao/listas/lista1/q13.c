#include <stdio.h>
/*
  Escreva um programa que leia duas variaveis A e B e efetue a troca dos valores. O objetivo  ́e que a
  variavel A passe a conter o valor de B e a vari ́avel B passe a possuir o valor de A. Apresente os valores
  aṕos a efetivação do processamento da troca.
*/

int main(void) {
  int A = 0, B = 0, C = 0;
  printf("\nA : ");  scanf("%i", &A);
  printf("B : ");  scanf("%i", &B);

  C = A;  A = B;  B = C;
  
  printf("\n\nA : %i\nB : %i\n", A, B);
  

  return 0;
}