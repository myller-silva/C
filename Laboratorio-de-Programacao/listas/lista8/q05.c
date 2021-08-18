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

int main (){
  NODE *n = NULL;
  int c=1, pos=-1;
  char esc[MX];

  srand(time(NULL));
  system("clear");  
  do{
    printf("\n---Node %d---", c);
    n = realloc(n, sizeof(NODE)*c);
    printf("\nDigite o valor de X: ");
    scanf("%d", &(n+c)->x);
    printf("Digite o valor de Y: ");
    scanf("%d", &(n+c)->y);    
    // 
    printf("Posicao: ");
    scanf("%d", &pos);
    //  
    T: 
    getchar();
    printf("Quer continuar? [s/n] : ");  
    scanf("%s", esc);
    if(esc[0]!= 's' && esc[0]!= 'n'){
      goto T;
    }
    c++;
  }while(esc[0]!='n');

  return 0;
}
