#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define INTERVALO 20

void ord_sel(int *, int );

//ordenando por seleção  
int main(){
  int c=0;
  int v[TAM];
  srand(time(NULL)); //semente
  // preencher:
  for(c=0; c<TAM; c++){
    *(v+c) = rand()%INTERVALO;
  }

  printf("\nAntes:\t");
  for(c=0; c<TAM; c++){
    printf("%d\t", *(v+c));
  }
  ord_sel(v, TAM);
  printf("\nDepois:\t");
  for(c=0; c<TAM; c++){
    printf("%d\t", *(v+c));
  }
  puts("");
  return 0;
}


void ord_sel(int *pV, int tam){
  int c, j, temp;   
  for(int c=0;c<tam-1;c++){
    for(int j=c+1; j<tam;j++){
      if(*(pV+j)<*(pV+c)){
        temp = *(pV+j)    ;
        *(pV+j) = *(pV+c) ;
        *(pV+c) = temp    ;
      }
    }
  } 
}