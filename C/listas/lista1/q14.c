#include <stdio.h>
/*
  Escreva um programa que leia uma temperatura em graus Celsius e apresente convertida em graus
  Fahrenheit. A f ́ormula de vers̃ao  ́e F = (9 * C + 160) / 5, sendo F a temperatura Fahrenheit e C a
  temperatura em Celsius.
*/
int main(void) {
  float c = 0, f = 0;
  printf("Digite uma temperatura em Celsius: ");
  scanf("%f", & c);
  f = (9 * c + 160)/5;
  printf("%.1f Celsius equivale a %.1f Fahrenheit\n ", c, f);
  return 0;
}