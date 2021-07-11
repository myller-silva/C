#include <stdio.h>
#define DOLAR 5.35
/*
  Elabore um programa que apresente o valor da convers ̃ao em d ́olar de um valor lido em real. O
  programa deve solicitar o valor da cota ̧c ̃ao do d ́olar e tamb ́em a quantidade de reais que o usu ́ario
  deseja converter.
*/
int main(void) {
  float num = 0, r = 0;
  printf("Digite um numero: \n");
  scanf("%f", &num);
  r = num / DOLAR;
  printf("%.2f reais equivale a %.2f dolares\n", num, r);




  return 0;
}