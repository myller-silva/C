#include <stdio.h>

// prototipos de funcoes
int soma(int x, int y);

// funcao principal
int main(void) {
  int a, b, s;
  puts("Digite a e b: ");
  scanf("%d%d", &a, &b);
  s = soma(a, b);
  printf("%d + %d = %d", a, b, soma(a, b));
  return 0;
}

// implementação das funcoes
int soma(int x, int y){
  int som = x + y;
  return som;
}