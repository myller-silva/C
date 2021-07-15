#include <stdio.h>
/*
  Escreva um programa que receba a entrada de um n ́umero de trˆes d ́ıgitos, separe o n ́umero em seus
  d ́ıgitos componentes e reconstrua um n ́umero com os componentes na ordem inversa. Exemplo: para
  entrada de 123, a resposta do programa seria 321.
*/
int main(void) {
  char n[3];
  printf("digite um numero: ");
  scanf("%s", &n[0]);
  printf("invertido: %c%c%c\n", n[2], n[1], n[0]);
  return 0;
}