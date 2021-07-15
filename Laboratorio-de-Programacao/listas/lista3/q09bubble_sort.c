#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 15

int main(void) {
  int intervalo;
  int vetor[TAM]; 
  int *pV=NULL;
  puts("Digite o intervalo desejado: ");
  scanf("%d", &intervalo);
  srand(time(NULL));
  // gerando os numeros pseudo aleatorios
  for(int c=0;c<TAM;c++){
    vetor[c] = rand()%intervalo;
  }
  
  pV = &vetor[0];

  puts("O vetor gerado foi:");
  for(int c=0;c<TAM;c++){
    printf("%d ", *(pV+c));
  } 
  //bubble sort
  int k, j, auxiliar;
  for (k = TAM - 1; k > 0; k--) {
      for (j = 0; j < k; j++) {
        if (*(pV+j) > *(pV+j+1)) {
            auxiliar = *(pV+j);
            *(pV+j) = *(pV+j+1);
            *(pV+j+1) = auxiliar;
        }
    }
  } 
  puts("\nO vetor ordenado:");
  for(int c=0;c<TAM;c++){
    printf("%d ", *(pV+c));
  }
  return 0;
}