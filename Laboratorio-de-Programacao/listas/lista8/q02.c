// Modifique o programa anterior adicionando um campo z com a m´edia aritm´etica de (x, y). A
// m´edia deve ser calculada por uma fun¸c˜ao e a estrutura passada por referˆencia. O tipo de retorno
// dessa fun¸c˜ao deve ser void.
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
