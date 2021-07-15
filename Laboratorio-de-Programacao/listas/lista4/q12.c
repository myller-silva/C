#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7 // m(4x4)

int main(void) {
  int x[N*2] = {0}, y[N*2] = {0}, f[N][N] = {0};   
  int c=0, l=0 , r[N*2] = {0};

  srand(time(NULL)); //semente
  // gerando nº pseudo aleatorios:
  for(c=0; c<N*2;c++){
    *(x+c) = rand()%N;  
    r[c] = rand()%N;

    (x[c]==1)&&(3<r[c])&&(r[c]<=5) ? y[c] = 0 : 
    (x[c]==2)&&(7<r[c])&&(r[c]<=9) ? y[c] = 0 :     
    (0<=r[c])&&(r[c]<=3) ? y[c] = x[c]    :
    (3<r[c])&&(r[c]<=5) ? y[c] = x[c] -1  : 
    (5<r[c])&&(r[c]<=7) ? y[c] = x[c] +1  :
    (7<r[c])&&(r[c]<=9) ? y[c] = x[c] -2  :
    (9<r[c])&&(r[c]<=10)? y[c] = x[c] +2  : -1 ;

    f[x[c]][y[c]] += 1 ; //frequencia 
  }
  // mostrando numeros pseudo aleatorios
  puts("\t\t(X, Y) : r");
  for(c=0; c<N*2;c++){ 
    printf("\t\t(%d, %d) : %d\n", *(x+c), *(y+c), *(r+c));
  }
  //matriz 
  printf("\n\t\t>>>Matriz %dx%d<<<\n\n", N, N);
  for(int l=0; l<N; l++){
    for(c=0; c<N; c++){
      printf("%10d",  f[l][c]);      
    }
    puts("\n");
  }  
  printf("\n\t\t\t\t\t\t\t (X x Y)\n");  

  return 0;
}