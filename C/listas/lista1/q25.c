#include <stdio.h>

int main(void) {
  float s = 0, h = 0, m = 0 ;
  printf("\nInforme quantos segundos sao: ");
  scanf("%f", &s);
  m = s/60;
  h = m/60;
  printf("%.2f segundos equivale a %.2f minutos e a %.2f horas\n", s, m, h);



  return 0;
}