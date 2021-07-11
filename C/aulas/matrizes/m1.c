#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define INTERVALO 10

int main(){
  int c=0; 
  int *v=NULL;
  v = realloc(v, N*N*sizeof(int));
  srand(time(NULL));
  for(c=0; c<N*N; c++){
    v[c] = rand()%INTERVALO;
  }
  printf("\n>>> Matriz %dx%d <<<\n", N, N);
  for(c=0; c<N*N; c++){
    if (c%N==0){
      puts("");
    }
    if(v[c]==0){
      printf("    0");
    }else{
      printf("%5.d", v[c]);
    }
  }
  printf("\nDiagonal principal: ");
  for(c=0; c<N*N; c+=(N+1)){
    printf("%d ", v[c]);
  }
  printf("\nDiagonal secundaria: ");
  for(c=N*N-1; c>=0; c-=(N+1)){
    printf("%d ", v[c]);
  }  
  puts("");

  return 0;
}