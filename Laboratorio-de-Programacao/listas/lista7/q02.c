// Escreva um programa em C que utilize uma Estrutura estoque que cont ́em uma string com o
// nomePeca, um n ́umero inteiro para identificar o n ́umero da pe ̧ca, o pre ̧co em ponto flutuante e um
// elemento inteiro para identificar o n ́umero do pedido.

#include <stdio.h>
#include <stdlib.h>
#define NP 10
#define T 3

struct estoque{
  char nomePeca[NP];
  int num;
  float preco;
  int num_pedido;
};

int main(){
  struct estoque est;
  // entrada:
  printf("Nome da %d peça: ", 1);
  scanf("%s", est.nomePeca);    
  printf("Numero: ");    
  scanf("%d", &est.num);
  printf("Preço: ");
  scanf("%f", &est.preco);
    
  printf("Numero do pedido: ");        
  scanf("%d", &est.num_pedido);


  return 0;
}