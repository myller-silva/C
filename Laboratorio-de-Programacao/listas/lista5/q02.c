#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 200
int main(void) {
  int n=0, c=0;
  int *p=NULL;
  srand(time(NULL));

  puts("Digite o valor de N: ");
  scanf("%d", &n);
  // alocação dinamica
  p = realloc(p, n*n*sizeof(int));
  // gerar valores
  for(c=0; c<n*n;c++){
    *(p+c) = rand()%(TAM+TAM)-TAM ;
  }  
  // mostrar matriz
  printf("Matriz %dx%d\n", n, n);
  for(c=0; c<n*n;c++){
    printf("[%4.d]\t", *(p+c));
    !((c+1) % n)?puts("") : -1;
  }
  // diagonal principal
  puts("\nDiagona principal:");
  for(c=0; c<n*n; c++){
    if ( !(c%(n+1)) ){
      printf("%6.d", *(p+c));
    }
  }
  // diagonal secundaria 
  puts("\nDiagonal secundaria: ");
  for(c=0; c<n*n; c++){
    if ( (c%(n-1)==0) && (c!=0) && (c!=(n*n-1)) ){
      printf("%6.d", *(p+c));
    }
  }
  free(p);
  return 0;
}