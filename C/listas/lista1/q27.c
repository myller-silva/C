#include <stdio.h>
#include <math.h>
/*
  Escreva um programa que solicite 3 n ́umeros em ponto flutuante e imprima a m ́edia aritmetica e
  geometrica. (Utilize a funcao pow(base, expoente) da biblioteca math.h).
*/
int main(void) {
  double n1 = 0, n2 = 0, n3 = 0, ma = 0, mg = 0 ;
 
  printf("Informe o primeiro numero: ");
  scanf("%lf", &n1);

  printf("Informe o segundo numero: ");
  scanf("%lf", &n2);

  printf("Informe o terceiro numero: ");
  scanf("%lf", &n3);
  
  ma = (n1+n2+n3)/3;
  mg = pow(n1*n2*n3, 1.0/3.0);
  printf("media aritmetica: %.2f\nmedia geometrica: %.2lf\n", ma, mg);
  return 0;
}