#include <stdio.h>
/*
  Escreva um programa que leia um n ́umero inteiro e positivo F e calcule o fatorial deste n ́umero.
*/
int main(void) {
  int fat = 1, f = 0;
  printf("Digite um numero: ");
  scanf("%i", &f);
  if (f >= 0){
    while (f > 0){
    fat *= f;
    f--;
    }
  printf("%i", fat);
  }else{
    printf("Invalido");
  }

  return 0;
}