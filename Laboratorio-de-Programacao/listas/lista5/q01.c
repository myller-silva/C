#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LI 82
#define LS 237

int main(void) {
  int *v=NULL;  
  srand(time(NULL));
  int qt=0, c=0, soma=0;
  puts("Digite a quantidade: ");
  scanf("%d", &qt);
  // alocação dinamica
  v = realloc(v, qt*sizeof(qt));
  // gerar valores
  for(c=0;c<qt;c++){
    *(v+c) = rand()%(LS-LI) + LI;
  }
  // somar valores
  for(c=0; c<qt;c++){
    soma += *(v+c);
  }
  // mostrar valores
  for(c=0;c<qt;c++){
    printf("[%p]\t%d\n", (v+c), *(v+c));
  }
  printf("\nSoma: %d\n", soma);
  return 0;
}