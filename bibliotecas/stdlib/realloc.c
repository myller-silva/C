#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

int main(void) {
  int *p=NULL;
  int qt=0, c, cqt=0;
  srand(time(NULL));
  do{
    puts("Digite a quantidade: ");
    scanf("%d", &qt);
    // alocação dinamica
    p = (int*)realloc(p, qt * sizeof(int));
    // gerar valores
    for(c=cqt; c<qt; c++){
      *(p+c) = rand()%TAM;
    }
    for(c=0; c<qt; c++){ 
      printf("[%p]  %d \n", (p+c), *(p+c));
    }  
    cqt = qt;
  }while(qt);
  free(p);
  return 0;
}