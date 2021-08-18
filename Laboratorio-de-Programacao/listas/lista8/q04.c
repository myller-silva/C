// Modifique Node para que a tenha um elemento ponteiro prox do tipo struct node. Esse ponteiro
// deve apontar para um pr´oximo node do vetor, sendo que o ´ultimo deve apontar para o primeiro.
// Imprima a m´edia do node atual e do seguinte.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3
#define MX 100

struct Node
{
  int x;
  int y;
  float media;
  struct Node *prox;
};
int main(){
  srand(time(NULL));
  system("clear");  

  struct Node *pv=NULL;

  pv = (struct Node *) malloc( sizeof(struct Node)*TAM ) ;
  
  for (int c=0; c<TAM; c++){
    (pv+c)->x = rand()%MX;
    (pv+c)->y = rand()%MX;
    (pv+c)->media = ( (pv+c)->x + (pv+c)->y ) / 2.0 ;
  }
  for (int c=0; c<TAM; c++){
    if (c == TAM-1){
      (pv+c)->prox = pv;
    }else{
      (pv+c)->prox = (pv+c+1);
    }
  }
  for (int c=0; c<TAM; c++){
    printf("---Node %d---\n", c+1);
    printf("x: %2d, y: %2d \n", (pv+c)->x, (pv+c)->y ); 
    printf("media do atual: %.2f\nmedia do seguinte: %.2f\n\n", (pv+c)->media, (pv+c)->prox->media ); 
  } 
  // exibir_prox(&pv[2]); //exibir_prox(pv+2);
  return 0;
}