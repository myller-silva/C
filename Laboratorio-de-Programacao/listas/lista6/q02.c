#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MX 10

void preencher_v(int *, int);
void exibir_v(int *, int);
void exibir_menor_v(int *, int);

// alocação dinamica - ok
// vetores aleatorios - ok
// menor valor - ok

int main(int argc, char *argv[]){
  // verificar formato
  if(argc!=2){
    printf("Formato:\n\t%s <tam>\n", argv[0]);
    exit(1);
  }  
  int *p=NULL, c;
  // alocaçao dinamica
  p = realloc( p, atoi(argv[1])*sizeof(int) );
  preencher_v( p, atoi((argv[1])) );
  exibir_v( p, atoi(argv[1]) );
  exibir_menor_v( p, atoi(argv[1]) );
  free(p);
  return 0;
}
void preencher_v(int *p, int tam){
  int c;
  // semente
  srand(time(NULL));
  for(c=0;c<tam; c++){
    *(p+c) = rand()%MX; 
  }
}
void exibir_v(int *p, int tam){
  int c;
  for(c=0; c<tam; c++){
    printf("[%p] %d\n", p+c, *(p+c));
  }
}
void exibir_menor_v(int *p, int tam){
  int *p_menor=NULL, menor, c;
  menor = *p;
  for(c=1; c<tam; c++){
    if (menor > *(p+c)){
      menor = *(p+c);
    }
  }
  for(c=1; c<tam; c++){
    if(*(p+c)==menor){
      p_menor = p+c;
      break;
    }
  }
  printf("menor: [%p] %d\n", p_menor, menor);
}