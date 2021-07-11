#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 3
#define I 10

int main(){
  srand(time(NULL));

  int *x=NULL, *v[2]={0};
  int c=0;
  // alocar:
  x = realloc(x, TAM*sizeof(int));
  // gerar:
  for(c=0; c<TAM; c++){
    x[c] = rand()%I;
  }
  // par:
  for(c=0; c<TAM; c++){
    // v[0] = 0;
    if(!(x[c]%2)){
      v[0] = &x[c];
      break;
    }
  }
  // impar:
  for(c=0; c<TAM; c++){
    if(x[c]%2){
      v[1] = &x[c];      
      break;
    }
  }
  for(c=0; c<TAM; c++){
    printf("[%p]\t%d\n", x+c, *(x+c));
  }
  printf("end. par:\t[%p]\n", v[0]);
  printf("end. impar:\t[%p]\n", v[1]);
  return 0;
}