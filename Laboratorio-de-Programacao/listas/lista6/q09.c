#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define L 10

void gerar_mxm(int *, int, int);
void exibir_mxm(int *, int);
int somar_d_mxm(int *, int);
void exibir_dp(int *, int);
void impar_par(int);

int main(){
  int *m=NULL, soma=0;
  srand(time(NULL)); //semente
  m = realloc(m, N*N*sizeof(int));
  gerar_mxm(m, N, L);
  soma = somar_d_mxm(m, N);
  exibir_mxm(m, N);
  exibir_dp(m, N);
  printf("\nsoma da diagonal: %d\n", soma);
  printf("%d é ", soma);
  impar_par(soma);

  return 0;

}

void gerar_mxm(int *m, int dim, int lim){
  int c=0;
  for(c=0; c<dim*dim; c++){
    *(m+c) = rand()%lim;
  }
}
void exibir_mxm(int *m, int dim ){
  int c=0;
  printf("\n\tMatriz %dx%d\n", dim, dim);
  for(c=0; c<(dim*dim); c++){
    if ( (c%dim==0) && (c!=0) ){
      puts("\n");
    }
    (*(m+c)==0)?printf("    0") : printf("%5.d", *(m+c));
  }
  puts("");    
}
void exibir_dp(int *m, int dim){
  int c=0;
  printf("\nDiagonal principal: ");
  for( c=0; c<dim*dim; c+=(dim+1) ){
    printf("%d ", *(m+c) );    
  }  
}
int somar_d_mxm(int *m, int dim){
  int c=0, somatorio=0;
  for( c=0; c<dim*dim; c+=(dim+1) ){
    somatorio +=  *(m+c) ;
  }
  return somatorio;  
}
void impar_par(int n){
  (n%2) ? printf("impar\n") : printf("par\n");
}