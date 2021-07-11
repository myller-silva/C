#include <stdio.h>
#include <math.h>
/*
  Elaborar um programa que apresente a m ́edia aritm ́etica dos n ́umeros inteiros existentes entre uma
  faixa especificada pelo usu ́ario.
*/
int main(void) {
  int  soma = 0, n1 = 0, n2 = 0, tot = 0;
  printf("Digite o primeiro numero: ");
  scanf("%i", &n1);
  printf("Digite o segundo numero: ");
  scanf("%i", &n2);
  int i = (n1<n2)?n1: n2, f = (n2>n1)?n2:n1;
  for (int c = i ; c<=f ; c++){
    soma += c;
    printf("%i", c);
    tot++;
    (c<f)? printf(" + ") : printf(" = ");
  }
  printf("%i\n", soma);
  float media = soma/tot;
  printf("\nMedia do somatorio no intervalo [%i, %i] = %f\n",n1, n2, media);

  return 0;
}