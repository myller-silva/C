#include <stdio.h>
/*
  Escreva um programa que mostre a diferen ̧ca entre pr ́e-incrementar e p ́os-incrementar usando o ope-
  rador –.
*/

int main(void) {
  int pre = 100, pos = 100;
  
  while(1){
    
    printf("Pre-incremento: %i =-=-= Pos-incremento: %i\n", --pre, pos--);
    if (pre == 90){
      break;
    }
  }
  return 0;
}