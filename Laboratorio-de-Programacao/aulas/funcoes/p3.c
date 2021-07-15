#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void exibir_v(int *, int);
void gerar_v(int *, int, int);
void exibir_menor_v(int *v, int tam);
// pseudoaleatorios ok
// passagem por referencia ok
// alocação dinamica ok
// menor
int main(int argc, char *argv[]) {
  int *vetor=NULL, c;
  if (argc != 3){
    printf("Formato:\n\t%s <tam> <intervalo>\n", *argv);
    exit(1);
  }
  // alocação dinamica
  vetor = realloc( vetor, atoi(*(argv+1)) * sizeof(int) );
  gerar_v(vetor, atoi(argv[1]), atoi(argv[2]) );
  exibir_v(vetor, atoi(*(argv+1)) );
  exibir_menor_v(vetor, atoi(*(argv+1)) );  
  return 0;
}
void gerar_v(int *v, int tam, int intervalo){
  int c;
  srand(time(NULL)); //semente
  for(c=0; c<tam; c++){
    *(v+c) = rand()%intervalo;
  }
}
void exibir_v(int *v, int tam){
  int c;
  for(c=0; c<tam; c++){
    printf("[%p] [%d]\n", v+c, *(v+c));
  }
}
void exibir_menor_v(int *v, int tam){
  int c, menor = *v, *p_menor=NULL;
  for(c=1; c<tam; c++){
    if( *(v+c)<menor){
      menor = *(v+c);
    }
  }
  for(c=1; c<tam; c++){
    if( *(v+c)==menor){
      p_menor = v+c; 
      break;
    }
  }
  printf("menor: [%p] [%d]\n", p_menor, *p_menor);
}