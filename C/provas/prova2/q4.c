#include <stdio.h>
#include <stdlib.h>
#define TAM 4
int *func(int *v, int tam, int x);

// int main(){
//   int v[TAM] = {3, 2, 4, 2}, *p=NULL;
//   p = func(v, TAM, 2);
//   for(int c=0; c<TAM; c++){
//     printf("[%p]\t=\t%d\n", v+c, *(v+c));
//   }  
//   printf("End de x=2: %p\n", p);
// }


int *func(int *v, int tam, int x){
  int *p=NULL;
  int c=0;
  for (c=0; c<tam; c++){
    if(x==v[c]){
      p = &v[c];
    }
  }
  return p;
}