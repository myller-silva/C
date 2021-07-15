#include <stdio.h>
#include<stdlib.h>
#define TAM 3
int main(void) {
  int matriz[TAM][TAM];
  int *pM3x3=NULL;
  int c=1;
  for(int linha = 0;linha<TAM;linha++){
      for(int coluna = 0;coluna<TAM;coluna++){
        printf("Digite o valor de [%d][%d]\n", linha, coluna);
        scanf("%d", &matriz[linha][coluna]);
      }    
  } 
  system("clear"); //está declarada na stdlib.h
  pM3x3 = &matriz[0][0] ;
  printf(">>> MATRIZ %dx%d <<<\n", TAM, TAM);
  for (int c=0; c<TAM*TAM;c++){
    !(c%TAM)?puts("") : -1;
    printf("%5.d", *(pM3x3+c));    
  }
  puts("\nElementos da diagonal principal: ");
  for (int c=0; c<TAM*TAM;c+=(TAM+1)){
    printf("%d ", *(pM3x3+c));
  }
  puts("\nElementos da diagonal Secundaria: ");
  for (int c=0; c<TAM*TAM;c+=TAM-1){
    if((c!=0)&&(c!=TAM*TAM-1)){
      printf("%d ", *(pM3x3+c));
    }
  }
  return 0;
}