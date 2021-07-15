#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMF 10 // n == 10
#define TAMX 30 

int main(void) {
  int f[TAMF] = {0}, x[TAMX] = {0};  //entendi, obrigado
  srand(time(NULL)); //semente
  int *px=NULL, *pf=NULL; 
  int e=0, c=0, soma=0;
 
  px = x;
  pf = f;
  // gerando nº pseudo aleatorios
  for(c=0; c<TAMX;c++){
    *(x+c) = rand()%TAMF;    
    printf("%d ", *(x+c));     
    // frequencia             
    (*(f+*(x+c)))++; // f[x[c]]++;  // eu nao cogitei isso, obrigado
    // for(e=0; e<TAMF;e++){
    //   if(x[c]==e){
    //     f[e] += 1 ; // 
    //   }
    // } 
	}  
  for(int n=0; n<TAMF; n++){
    printf("\nf[%d] = %d", n, *(f+n));
    soma += *(f+n);
  }
  printf("\nsoma: %d", soma);    
  return 0;
}