#include <stdio.h>
#include <math.h>
/*
  Fazer um programa para ler as coordenadas x e y de dois pontos e calcular a distˆancia entre os dois
  pontos no plano. (Utilize a fun ̧c ̃ao sqrt (numero), biblioteca math.h).
*/
int main(void) {
  double x1 = 0, x2 = 0, y1 = 0, y2 = 0, d = 0;
  printf("Informe o ponto A\nx: ");
  scanf("%lf", &x1);
  printf("y: ");
  scanf("%lf", &y1);

  printf("Informe o ponto B\nx: ");
  scanf("%lf", &x2);
  printf("y: ");
  scanf("%lf", &y2);

  d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  printf("A distancia do ponto A = (%.2lf, %.2lf) e B = (%.2lf, %.2lf) é d = %.2lf", x1, y1, x2, y2, d);


  return 0;
}