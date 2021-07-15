#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void gerar_v(int *, int , int );
void exibir_v(int *, int );

void  inicializar_mxm( int dim, int matriz[dim][N]);
void  exibir_mxm( int dim, int matriz[dim][dim]);
void frequencia_mxm(int m[N][N], int *v1, int *v2, int tam_v);


int main(){
  int m[N][N];
  int *x=NULL, *y=NULL;
  int c=0;
  // alocação dinamica
  x = realloc(x, N*2*sizeof(int));
  y = realloc(y, N*2*sizeof(int)); 

  srand(time(NULL)); // semente
  
  gerar_v (x, N*2, N);
  gerar_v (y, N*2, N);
  inicializar_mxm(N, m);
  frequencia_mxm(m, x, y, N*2);
  // for(c=0; c<N*2; c++){
  //   m[y[c]][x[c]] += 1;
  // }

  printf("\nX: ");
  exibir_v(x, N*2);
  printf("Y: ");  
  exibir_v(y, N*2);  
  printf("\n>>>Matriz %dx%d<<<", N, N);  
  exibir_mxm(N, m);
  
  return 0;
}

void gerar_v(int *vector, int tam, int intervalo){
  int c=0;
  vector = realloc(vector, tam*sizeof(int));
  for(c=0; c<tam; c++){
    *(vector+c) = rand() % intervalo;
  }  
}
void exibir_v(int *vector, int tam){
  int c=0;
  for(c=0; c<tam; c++){
    printf("%d ", *(vector + c));
  }
  puts("");
}
void  inicializar_mxm( int dim, int matriz[dim][dim]){
  int c=0, c2=0;
  for(c=0; c<dim; c++){
    for(c2=0; c2<dim; c2++){
      matriz[c][c2] = 0;
    }
  }
}
void frequencia_mxm(int m[N][N], int *v1, int *v2, int tam_v){
  int c=0;
  for(c=0; c<N*2; c++){
    m[v2[c]][v1[c]] += 1;
  }  
}
void  exibir_mxm( int dim, int matriz[dim][dim]){
  int c=0, c2=0;
  for(c=0; c<dim; c++){
    printf("\n\t");
    for(c2=0; c2<dim; c2++){
      printf("%d ", matriz[c][c2]);
    }
  }
  puts("");
}