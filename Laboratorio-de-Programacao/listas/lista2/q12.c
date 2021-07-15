#include <stdio.h>
/*
  Elaborar um programa que mostre os resultados da tabuada de um n ́umero inteiro qualquer, a qual
  deve ser apresentada de acordo com sua forma tradicional.
*/

int main(void) {
  int n = 0;
  printf("Digite um numero: ");
  scanf("%i", &n);
  printf(">>>TADUBADA DO %i<<<\n", n);
  for (int cont = 1 ; cont <= 10 ; cont++){
    printf("%i x %i = %i\n", n, cont, n*cont);
  }
  return 0;
}