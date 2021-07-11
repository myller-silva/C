#include <stdio.h>
#define TAM 6
//bubble sort
void bulble_sort(int * , int );

int main(){
  int v[TAM] ={6, 4, 3, 5, 2, 1};
  
  printf("Antes:\t");
  for (int c=0; c<TAM; c++){
    printf("%d\t", *(v+c));
  }
  printf("\nDepois:\t");

  bulble_sort(v, 6);
  for (int c=0; c<TAM; c++){
    printf("%d\t", *(v+c));
  }
  puts("");

  return 0;
}
void bulble_sort(int *pV, int tam){
  int k, j, auxiliar;
  for (k = tam - 1; k > 0; k--) {
    for (j = 0; j < k; j++) {
      if (*(pV+j) > *(pV+j+1)) {
        auxiliar = *(pV+j);
        *(pV+j) = *(pV+j+1);
        *(pV+j+1) = auxiliar;
      }
    }
  } 
}
