#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7 
int main(void) {
  int x[N*2] = {0}, y[N*2] = {0}, f[N][N] = {0};   
  int c=0, l=0 ;

  srand(time(NULL)); //semente
  // gerando nº pseudo aleatorios:
  for(c=0; c<N*2;c++){
    *(x+c) = rand()%N;  
    *(y+c) = rand()%N;  
    f[x[c]][y[c]] += 1 ; //frequencia 
  }
  // mostrando numeros pseudo aleatorios
  puts("\t\t(X, Y)");
  for(c=0; c<N*2;c++){ 
    printf("\t\t(%d, %d)\n", *(x+c), *(y+c));
  }
  //matriz 
  printf("\n\t\t>>>Matriz %dx%d<<<\n\n", N, N);
  for(int l=0; l<N; l++){
    for(c=0; c<N; c++){
      printf("%10d",  f[l][c]);      
    }
    puts("\n");
  }

  printf("\n\t\t\t\t\t\t\t (X x Y)");  
  return 0;
}