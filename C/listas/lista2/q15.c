#include <stdio.h>
#include<math.h>
/*
  Elaborar um programa que apresente os resultados das potˆencias do valor de base 3, elevado a um
  expoente que varie do valor 0 a 7. 
*/
int main(void) {
  for (int cont = 0 ; cont <= 7 ; cont++){
    printf("3^%i = %0.f\n", cont, pow(3, cont));
  }
  return 0;
}