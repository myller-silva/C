#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define I 100

struct node{
    int x;
    struct node *prox;
};

void exibir_n0_e_n1(struct node * );

int main(){
    struct node x1, x2, x3, x4;
    srand(time(NULL));
    x1.x = rand()%I;
    x2.x = rand()%I;    
    x3.x = rand()%I;    
    x4.x = rand()%I;

    x1.prox = &x2;
    x2.prox = &x3;
    x3.prox = &x4;
    x4.prox = NULL;

    printf("\n\n%2d\n", x1.x);
    printf("%2d\n", x2.x);
    printf("%2d\n", x3.x);
    printf("%2d\n\n", x4.x);

    exibir_n0_e_n1(&x4);

    return 0;
}

void exibir_n0_e_n1(struct node *n){
  printf("x: %d\n", n->x);
  if(n->prox == NULL){
    puts("ultimo elemento da lista");
  }else{
    printf("x do proximo: %d\n", n->prox->x);
  }
}