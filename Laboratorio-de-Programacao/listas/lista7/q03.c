// Escreva um programa em C que gere um vetor com n ́umeros aleat ́orios e calcule sua m ́edia. Orga-
// nize uma Estrutura com as seguintes informa ̧c ̃oes: ponteiro para a matriz, quantidade de elementos

// e a m ́edia.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define D 3
#define I 10 // [0, 9]

struct m{
  int *pmxm;
  int qt;
  float med;
};
void exibir_mxm(int *, int );

int main(){
  int *matriz=NULL;
  matriz = realloc( matriz, D*D*sizeof(int) );

  struct m mxm;
  mxm.pmxm = matriz;
  mxm.qt = D*D;

  srand(time(NULL));

  // gerar valores:
  for(int c=0; c<D*D; c++){
    matriz[c] = rand()%I;
  }
  // somar:
  int soma=0;
  for(int c=0; c<D*D; c++){
    soma += matriz[c] ;
  }
  mxm.med =  (float)(soma) / mxm.qt;


  exibir_mxm(matriz, D);
  printf("\nPonteiro para a matriz: [%p]\n", mxm.pmxm);
  printf("Media: %.2f\n", mxm.med);

  return 0;
}

void exibir_mxm(int *mxm, int dim){
  int c=0;
  for(c=0; c<dim*dim; c++){
    if(c%dim==0){
      puts("");
    }
    printf("%d\t", *(mxm+c) );
  }
  puts("");
}