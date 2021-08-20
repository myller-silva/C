// Defina uma Estrutura para armazenar um par (x,y) de coordenadas. Organize um vetor com 10 elementos
// dessas Estruturas. Para cada Estrutura, imprima a soma (x+y) dos pontos armazenados sem
// uso de ponteiros. Gere os valores x e y aleatoriamente. Utilize o typedef e #define.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define I 100

typedef struct par_xy {
  float x;
  float y;
}Par_xy;

int main() {
  srand(time(NULL));
  Par_xy n[TAM]={};

  for(int c=0; c<TAM; c++){
    (n+c)->x = (( float ) rand () / ( float ) RAND_MAX) * I;
    (n+c)->y = (( float ) rand () / ( float ) RAND_MAX) * I;
  }
  for(int c=0; c<TAM; c++){
    printf("[%d] (%.2f, %.2f) = %.2f\n",c,(n+c)->x,(n+c)->y,  ((n+c)->x + (n+c)->y) );
  }

  return 0;
}
