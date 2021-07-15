#include <stdio.h>
/*
  Escreva um programa que calcule o produto entre um valor dado x por 2 elevado a um valor dado n.
  Obs.: Utilize operadores bin ́arios.
*/
int main(void) {
  int x = 0, n = 0, r = 1;
  printf("Digite um numero para x: ");
  scanf("%i", &x);
  printf("Digite um numero para n: ");
  scanf("%i", &n);
  for (int c = 0 ; c < n ; c++){
    r *= (x * 2);
  }
  printf("\n(x*2)^n = (%i*2)^%i = %i\n", x, n, r);

  return 0;
}