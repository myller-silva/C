// Crie uma fun ̧c ̃ao que receba, por referˆencia, um elemento da lista encadeada descrita na figura a seguir
// e imprima x do elemento fornecido e do seguinte. Imprima uma mensagem para o usu ́ario se o elemento
// recebido for o  ́ultimo da lista. O tipo de retorno dessa fun ̧c ̃ao deve ser void.

// Lembre-se de as c ́elulas da lista NAO ocupam posi ̧c ̃oes consecutivas na mem ́oria. Elas est ̃ao espalhadas  ̃
// na mem ́oria de forma imprevis ́ıvel. Defina a Estrutura.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define I 100

typedef struct lista {
  int x;
  struct lista *prox;
}LISTA;

void imprimir_n0_e_n1(LISTA *p);

int main(void) {

  LISTA n1, n2, n3, n4;

  n1.x = rand()%I;
  n2.x = rand()%I;
  n3.x = rand()%I;
  n4.x = rand()%I;
  
  n1.prox = &n2;
  n2.prox = &n3;
  n3.prox = &n4;
  n4.prox = NULL;

  printf("[1] x: %d\n", n1.x);
  printf("[2] x: %d\n", n2.x);
  printf("[3] x: %d\n", n3.x);
  printf("[4] x: %d\n", n4.x);

  puts("\n>>>n1<<<");
  imprimir_n0_e_n1(&n1);
  puts("\n>>>n2<<<");
  imprimir_n0_e_n1(&n2);
  puts("\n>>>n3<<<");
  imprimir_n0_e_n1(&n3);
  puts("\n>>>n4<<<");
  imprimir_n0_e_n1(&n4);
  
  return 0;
}

void imprimir_n0_e_n1(LISTA *p){
  printf("x: %d \n",p->x);
  if(p->prox==NULL){
    puts("este é o ultimo elemento da lista");
  }else{
    printf("x do proximo: %d\n", p->prox->x);
  }
}
