#include <stdio.h>
/*
  Escreva um programa que leia um valor nuḿerico inteiro e apresente como resultado os seus valores
  sucessor e antecessor.
*/
int main(void) {
  int n = 0;
  printf("Digite um numero: ");
  scanf("%i", &n);
  printf("antecessor: %i\nsucessor: %i\n", n-1, n+1);
  return 0;
}