#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 200
int main (){
  int **v_linhas=NULL, *matriz=NULL;
  int n=0, c=0, c2=0;
  srand(time(NULL));
  puts("Digite o valor de N: ");
  scanf("%d", &n);
  // alocação dinamica
  v_linhas = realloc(v_linhas, n*sizeof(n));
  matriz = malloc(n*n*sizeof(n));
  // gerar valores
  for(c=0; c<n*n; c++){
    *(matriz + c) = rand()%(TAM*2)-TAM;
  }
  // atribuir ponteiros das linhas
  for(c=0, c2=0; c<n; c++, c2+=n){
    *(v_linhas+c) = (matriz+c2);    
  }
  printf("Ponteiros:\t\tvalores: \n");
  for(c=0; c<n*n ; c++){    
    (c)%n==0&&c!=0?puts(""):-1;
    printf("[%p]\t\t[%5.d]\n", (matriz+c), *(matriz+c) );
  }
  printf("\nPonteiros das linhas: \n");
  for(c=0; c<n; c++){
    printf("%dª linha: [%p]\n", (c+1), *(v_linhas+c));
  }  
  printf("\n\t>>>Matriz %dx%d<<<\n", n, n);
  for(c=0; c<n*n; c++){
    ((c%n==0)&&(c!=0))?puts(""):-1;
    printf("[%5.d]\t", *(matriz+c));
  }
  return 0;
}