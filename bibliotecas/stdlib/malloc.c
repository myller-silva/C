#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10 //[0, 9]

int main(void) {
  int *t = NULL;
  unsigned int c, n;
  srand(time(NULL));
  puts("Quanto de memoria voce deseja?(byts) ");
  scanf("%d", &n);
  // alocação de memoria
  t = malloc(n * sizeof(n)); //retorna ponteiro do tipo void
  if (!t){
    puts("Sem memoria!!!");
    exit(1); //retorno de erro
  }
  for( c =0; c<n; c++){
    *(t+c) = rand()%TAM;
  }
  puts("Vetor gerado: ");
  for (c =0; c<n; c++){
    printf("%d ", *(t+c));
  }
  puts("");
  return 0;
}