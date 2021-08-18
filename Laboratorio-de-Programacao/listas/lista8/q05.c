// Crie uma lista encadeada com 3 nodes. Crie uma fun¸c˜ao para inserir um elemento node na lista e
// outra fun¸c˜ao para remover.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 100
#define TAM 3

typedef struct Node{
  int x;
  int y;
  struct Node *prox;
}NODE;

void inserir(NODE *);
void exibir(NODE *);

int main (){
  int qt=0;
  char esc[]={};
  NODE *n=NULL;

  system("cls");

  T:
  n = realloc(n, sizeof(NODE)*(qt+1));  
  inserir( (n+qt) ); 

  system("cls");
  puts("");

  for(int c=0; c<(qt+1); c++){
    printf("node %d: ", c+1);
    exibir(n+c);
  }
  puts("");
  
  E:
  printf("Quer continuar?[s/n] ");
  scanf("%s", esc);

  switch (esc[0]){
    case 's':
      qt++;
      goto T;    
    case 'n':
      return 0;
    default:
      goto E;
  }
  

  return 0;
}

void inserir(NODE *n){ 
  printf("X: ");
  scanf("%d", &( n->x));
  printf("Y: ");
  scanf("%d", &( n->y));
}

void exibir(NODE *n){
  printf("(%d,%d)\n", n->x, n->y);
}