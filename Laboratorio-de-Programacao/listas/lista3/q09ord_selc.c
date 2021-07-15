#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 15

int main(void) {
  int intervalo   ;
  int vetor[TAM]  ; 
  int *pV=NULL    ;
  int temp=0      ;
  puts("Digite o intervalo desejado: ");
  scanf("%d", &intervalo);
  srand(time(NULL)); //plantando a semente
  // gerar os numeros pseudo aleatorios:
  for(int c=0;c<TAM;c++){
    vetor[c] = rand()%intervalo;
  }
  pV = &vetor[0]; 
  //mostrando o vetor
  puts("O vetor gerado foi:");
  for(int c=0;c<TAM;c++){
    printf("%d ", *(pV+c));
  }   
  //ordenando por seleção  
  for(int c=0;c<TAM-1;c++){
    for(int j=c+1; j<TAM;j++){
      if(*(pV+j)<*(pV+c)){
        temp = *(pV+j)    ;
        *(pV+j) = *(pV+c) ;
        *(pV+c) = temp    ;
      }
    }
  } 
  puts("\nO vetor ordenado:");
  for(int c=0;c<TAM;c++){
    printf("%d ", vetor[c]); //*(vetor+c)
  }
  return 0;
}