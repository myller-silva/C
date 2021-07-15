#include <stdio.h>
/*
  Implementar um programa para resolver o seguinte problema: Jos ́e tem 150 cent ́ımetros e cresce 2
  cent ́ımetros por ano. O Pedro tem 110 cent ́ımetros e cresce 3 cent ́ımetros por ano. Em quantos anos
  Pedro ser ́a maior que Jos ́e?
*/

int main(void) {
  int jose = 150, pedro = 110, anos = 0;
    
  while(jose > pedro){
    jose += 2;
    pedro += 3;
    anos += 1;
  }
  printf("Em %i ano(s) Pedro será maior que José.", anos);
  
  return 0;
}