#include <stdio.h>
// Fa ̧ca um programa em C que leia um vetor de inteiros com 15 elementos e apresenta a sua soma.
#define TAM 15
int main(void) {
  int vector[TAM];
  int *p=NULL;
  int *c, k=0, soma = 0;
  p = &vector[0];

  for(c = p; c<&p[TAM] ;c++){
    printf("Digite o %dº valor: ", (k+1));
    scanf("%d", &*(p + k++));
    soma += *(p+k-1);
  }
  printf("Soma: %d\n", soma);

  return 0;
}