// Escreva um programa em C que organize em uma Estrutura o endere ̧co de um vetor alocado dinamicamente, a quantidade de elementos desse vetor e o maior valor presente no vetor. Para obter o maior

// valor, crie uma fun ̧c ̃ao o mais gen ́erica (reutiliz ́avel) poss ́ıvel. Observe que o vetor n ̃ao  ́e um elemento
// da Estrutura.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3
#define I 100

typedef struct N { 
  int valor;
  int qt;
  struct N *maior;
}N;

void maior(N *n, int tam);

int main() {
  N *v=malloc(sizeof(N)*TAM);
  
  v->qt = TAM;
  srand(time(NULL));

  for(int c=0; c< v->qt; c++){
    (v+c)->valor = rand()%I;
  }

  maior(v, v->qt);

  for(int c=0; c<v->qt; c++){
    printf("end: [%p] valor: %2d\n", v+c, (v+c)->valor );
  }

  printf("\nEndereco do maior valor: [%p]\n", v->maior);
  
  return 0;
}

void maior(N *n, int tam){
  int c=0;
  for(c=0; c<tam; c++){
    if(c==0){
      n->maior = (n+c);
    }else{
      if( (n+c)->valor > (n->maior->valor) ){
        n->maior = n+c;
      }
    }
  }
}
