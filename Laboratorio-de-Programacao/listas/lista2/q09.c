#include <stdio.h>
/*
  A s ́erie de Fibonacci  ́e formada pela seguinte sequˆencia: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55... etc. Escreva
  um algoritmo que gere a s ́erie de Fibonacci at ́e o vig ́esimo termo.
*/
int main(void) {
  int n1 = 1, n2 = 1, cont = 3, n3 = 0;
  printf("Termo 1: %i\nTermo 2: %i\n",n1, n2);
  while (cont<=20){
    n3 = n1 + n2;
    n1 = n2;
    n2 = n3;
    printf("Termo %i: %i\n",cont, n3);
    cont++;
  }
  return 0;
}