#include <stdio.h>
/* 8)
  Escreva um programa que receba um valor inteiro e apresente o resultado do valor lido elevado ao
  quadrado.
*/  
int main(){
  int n = 0;
  printf("\nDigite um numero: ");
  scanf("%i", &n);
  printf("%i^2 = %i \n", n,  n*n);
  return 0;
}