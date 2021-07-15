#include <stdio.h>
/*
  Elabore um programa que apresente os quadrados dos n ́umeros inteiros m ́ultiplos de 4 existentes na
  faixa de valores de 15 a 90.
*/
int main(void) {
  int n = 15;
  while ((15<=n)&&(n<90)){
    n++;
    if (n%4==0) 
      printf("%i\n", n);
  }
  return 0;
}