#include <stdio.h>
/*
  Elaborar um programa que apresente os valores de convers ̃ao de graus Celsius em graus Fahrenheit,
  de 10 em 10 graus, iniciando a contagem em dez graus Celsius e finalizando em cem graus Celsius. O
  programa deve apresentar os valores das duas temperaturas. Obs.: Pesquise a f ́ormula de convers ̃ao.
*/

int main(void) {
  int c = 10, f = 0;
  for (c = 10 ; c<=100 ; c+= 10){
    f = (((9*c)/5)+32);
    printf("\n%i°C = %i°F.\n", c, f);
  }
  return 0;
}