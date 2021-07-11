#include <stdio.h>
/*
  Para que a divis ̃ao entre 2 n ́umeros possa ser realizada, o divisor n ̃ao pode ser nulo (zero). Escreva
  um programa para ler 2 valores e imprimir o resultado da divis ̃ao do primeiro pelo segundo. OBS: O
  programa deve validar a leitura do segundo valor (que n ̃ao deve ser nulo). Enquanto for fornecido um
  valor nulo a leitura deve ser repetida.
*/
int main(void) {
  float n1 = 0, n2 = 0, div = 0;
  printf("Primeiro numero: ");
  scanf("%f", &n1);
  while (n2 == 0){
    printf("Segundo numero: ");
    scanf("%f", &n2);  
  }
  div = n1/n2;
  printf("divisao: %.1f\n", div);
  return 0;
}