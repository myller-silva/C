#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3
#define I 100

typedef struct P {
  int x;
  int y;
}P;

P *distanciamenor(P *, int);

int main(void) {
  P *n = malloc(sizeof(P)*TAM) ;
  P *menor = malloc(sizeof(P)) ;
  
  srand(time(NULL));

  for(int c=0; c<TAM; c++){
    (n+c)->x = rand()%I;
    (n+c)->y = rand()%I;    
  }
  menor = distanciamenor(n, TAM);
  // exibir: 
  for(int c=0; c<TAM; c++){
    printf("(%d, %d)\n", (n+c)->x, (n+c)->y );
  }

  printf("menor distancia: %d\n", (menor->x - menor->y >= 0) ? menor->x - menor->y: menor->y - menor->x );

  return 0;
}


P *distanciamenor(P *n, int tam){
  P *menor = malloc(sizeof(P));
  int me=0;

  for(int c=0; c<TAM; c++){  
    if(c==0){
      if (n->x >= n->y){
        me = n->x - n->y;        
      }else{
        me = n->y - n->x;
      }
    }
  }
  for(int c=0; c<TAM; c++){
    if((n+c)->x - (n+c)->y == me || (n+c)->y - (n+c)->x == me){
      menor = n+c;
    }
  }
  return menor;
}