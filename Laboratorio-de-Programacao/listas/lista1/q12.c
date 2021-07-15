#include <stdio.h>
/*
  Escreva um programa que pȩca ao usúario para digitar dois ńumeros, obtenha-os do usuario e imprima
  a soma, o produto, a diferen ca, o quociente e o resto da divis ̃ao dos dois numeros.
*/
int main(void) {
  float n1 = 0, n2 = 0, som, dif, mult, div;
  printf("Digite o primeiro numero: ");
  scanf("%f", &n1);
  printf("Digite o segundo numero: ");
  scanf("%f", &n2);
  som = n1 + n2;
  dif = n1 - n2;
  mult = n1 * n2;
  div = n1 / n2;
  printf("\nSoma: %.2f\nDiferença: %.2f\nMultiplicação: %.2f\n", som, dif, mult);
  if (n2 != 0){
    printf("Divisão: %.2f\n", div);
  }else{
    printf("Divisão por zero é pecado\n");
  }
  return 0;
}