#include <stdio.h>
/*
  Escreva um programa que calcule e apresente o valor do volume de um caixa retangular utilizando a
  formula VOLUME = COMPRIMENTO * LARGURA * ALTURA.
*/

int main(void) {
  float l = 0, c = 0, h = 0, v = 0;
  printf("Informe a largura: \n");
  scanf("%f", &l);
  printf("Informe o comprimento: \n");
  scanf("%f", &c);
  printf("Informe a altura: \n");
  scanf("%f", &h);
  printf("O volume é: %.2f", l*c*h);
  
  return 0;
}