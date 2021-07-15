#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define MX 20

void float_pseudoaleatios(float *, int, int);
void exibir_v_float(float *, int);

int main(){
  int c=0;
  float *x=NULL;
  x = realloc(x, N*sizeof(float)); // alocação dinamica  
  srand(time(NULL)); //semente  
  float_pseudoaleatios(x, N, MX);
  exibir_v_float(x, N);
  
  free(x);
  
  return 0;
}
void float_pseudoaleatios(float *v, int tam, int intervalo){
  int c=0;
  for(c=0; c<tam; c++){
    *(v+c) = ((float)rand() / (float)RAND_MAX) * intervalo; // gerar float pseudoaleatorios
  }  
}
void exibir_v_float(float *v, int tam){
  int c=0;
  for(c=0; c<tam; c++){
    printf("%f ", *(v+c));
  }  
  puts("");
} 

// como gerar valores float pseudoaleatorios?
// okay, sem problemas
// sim, entendi, okay

// rand() -> [0 RAND_MAX]

// (float) rand() / (float) RAND_MAX -> [0 1]

// d + (rand() / RAND_MAX)* MX