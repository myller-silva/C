#include <stdio.h>
// Fa ̧ca um programa em C que leia um vetor do tipo float com 15 elementos e apresente a soma do
// menor e maior elemento do vetor fornecido.
#define TAM 3
int main(void) {
  float vector[TAM], *p=NULL, soma=0, maior, menor;
  p = &vector[0];
  
  for(int c=0; c<TAM;c++){
    printf("Digite o %dº valor: ", (c+1));
    scanf("%f", &*(p+c));
    soma += *(p+c);
    if (!c){
      maior = menor = *(p+c);
    }else{
      *(p+c)>maior ? maior = *(p+c):
      *(p+c)<menor ? menor = *(p+c): -1;
    }
  }  
  printf("\nSoma: %f\nMaior: %f\nMenor: %f", soma, maior, menor);
  return 0;
}