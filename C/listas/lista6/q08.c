#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 10 //limiar
#define MX 20 //intervalo

void exibir_mxm(int *, int );
void gerar_mxm(int *, int, int);
void binarizar_mxm(int *, int *, int, int);

int main(){
  int *m=NULL, *s=NULL, n=0, c=0;
  printf("Digite a dimensao da matriz: ");
  scanf("%d", &n);
  srand(time(NULL)); //semente
  // alocação dinamica
  m = realloc(m, n*n*sizeof(int));
  s = realloc(s, n*n*sizeof(int));

  gerar_mxm(m, n, MX);
  binarizar_mxm(m, s, n, T);
  exibir_mxm(m, n); 
  printf("\nBinarizado:\n");
  exibir_mxm(s, n); 
  free(m);
  free(s);
  return 0;
}

void binarizar_mxm(int *m, int *s, int dim, int lim){
  int c=0;
  for (c=0; c<dim*dim; c++){
    *(s+c) = (*(m+c)>lim) ? 1 : 0 ;
  }
}
void gerar_mxm(int *m, int dim, int intervalo){
  int c=0;
  for(c=0; c<dim*dim; c++){
    *(m+c) = rand()%intervalo;
  }
}
void exibir_mxm(int *m, int dim ){
  int c=0;
  printf("\tMatriz %dx%d\n", dim, dim);
  for(c=0; c<(dim*dim); c++){
    if ( (c%dim==0) && (c!=0) ){
      puts("\n");
    }
    (*(m+c)==0)?printf("    0") : printf("%5.d", *(m+c));
  }
  puts("");    
}