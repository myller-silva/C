#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5
#define I 100
typedef struct est{
  int *vetor;
  int qt;
  int *end_maior;  
}EST;

int *maior(int *, int );

int main() {
  int *vetor = malloc(sizeof(int)*TAM);  
  EST v;

  v.vetor = vetor;
  v.qt = TAM;
  
  srand(time(NULL));

  for(int c=0; c<v.qt; c++){
    v.vetor[c] = rand()%I ;
  }
  v.end_maior = maior(v.vetor, v.qt);

  // exibir:
  for(int c=0; c<v.qt; c++){
    printf("[%p]\t%d \n", &(v.vetor[c]), v.vetor[c]);
  }
  printf("\nEndereco do maior: [%p]", v.end_maior);
  
  return 0;
}

int *maior(int *v, int tam){
  int *maior = &v[0] ;
  int valor_temp = v[0];

  for(int c=1; c<tam; c++){
    if(v[c]>valor_temp){
      valor_temp = v[c];
      maior = &v[c];
    }
  }
  return maior;
}


// Escreva um programa em C que organize em uma Estrutura o endere ̧co de um vetor alocado dinami-
// camente, a quantidade de elementos desse vetor e um ponteiro para o maior valor contido nele. Para

// computar o maior valor, crie uma fun ̧c ̃ao o mais gen ́erica (reutiliz ́avel) poss ́ıvel. Observe que o vetor
// n ̃ao  ́e um elemento da Estrutura.