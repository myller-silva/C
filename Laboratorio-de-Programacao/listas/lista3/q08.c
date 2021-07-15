#include <stdio.h> 
#include <stdlib.h> //srand() e rand()
#include <time.h>
#include <math.h>
// Fa ̧ca um programa em C que gere um vetor com 3 n ́umeros inteiros pseudoaleat ́orios no intervalo
// [0, 19] e apresente a sua m ́edia aritm ́etica e geom ́etrica.
#define QUANTIDADE 3
#define INTERVALO 20 // [0, 19]
 
int main(void) {
  int n[QUANTIDADE];
  int *pN=NULL;
  float soma = 0, mult = 1;
  //gerando numeros pseudo aleatorios:
  srand(time(NULL));
  for(int c=0;c<QUANTIDADE;c++){
    n[c] = rand()%INTERVALO;
  }  
  //atribuir o endereço do primeiro elemento ao ponteiro
  pN = &n[0]; 
  puts("Os numeros pseudo aleatorios gerados foram: "); 
  for(int **c = &pN; pN<&n[QUANTIDADE];pN++){
    printf("%.2d no endereço %p \n", *pN, pN);
    soma += **c;
    mult *= **c;      
  }
  printf("\nMedia aritmetica: %f\nMedia geometrica: %f\n", soma/QUANTIDADE, pow(mult, 1.0/QUANTIDADE));
  return 0;
}