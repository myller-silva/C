#include <stdio.h>
#define PI 3.14159 
/*
  Escreva um programa que leia o raio de um c ́ırculo e imprima seu diˆametro, o valor de sua circunferˆencia
  e sua  ́area. Use o valor de 3,14159 para ”pi”. Fa ̧ca cada um destes c ́alculos dentro da instru ̧c ̃oes (ou
  instru ̧c ̃oes) printf e use o especificador de convers ̃ao %f.
*/

int main(void) {
  float r = 0 ;
  printf("Escreva o valor do raio: ");
  scanf("%f", &r);
  printf("Diametro: %f u\nCircunferencia: %f u\nArea: %f u.a\n", 2*r, 2*PI*r, 2*PI*r*r);

  return 0;
}