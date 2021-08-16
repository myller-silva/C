#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int x;
  int y;
  float z;
} Node ; 

int main(){
  Node *a=NULL;

  a = realloc(a, sizeof(Node)*1);

  printf("X: ");
  scanf("%d", &a->x);
  printf("Y: ");
  scanf("%d", &a->y);
  a->z = (a->x + a->y)/2.0;

  printf("x = %d\n", a->x);  
  printf("y = %d\n", a->y);
  printf("z = %.2f\n", a->z);
  
    
  return 0;
}
