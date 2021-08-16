#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int x;
  int y;
} Node ; 

int main(){
  Node *a=NULL;
  a = realloc(a, sizeof(Node)*1);
  
  printf("X: ");
  scanf("%d", &a->x);
  printf("Y: ");
  scanf("%d", &a->y);
  
  printf("x = %d\n", a->x);  
  printf("y = %d\n", a->y);

  return 0;
}