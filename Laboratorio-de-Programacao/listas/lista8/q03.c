// Modifique os programas anteriores para que agora tenhamos um vetor de Nodes. Utilize a diretiva
// define para definir a quantidade de elementos.#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int x;
  int y;
  float media;
} Node ; 

int main(){
  Node *a=NULL;
  a = malloc(sizeof(Node)*1);  

  printf("X: ");
  scanf("%d", &a->x);
  printf("Y: ");
  scanf("%d", &a->y);
  a->media = (a->x + a->y)/2.0;

  printf("x = %d\n", a->x);  
  printf("y = %d\n", a->y);
  printf("media = %.2f\n", a->media);

  return 0;
}