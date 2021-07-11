#include <stdio.h>

int incrementar(int a);

int main(){
  int (*pF)(int) = NULL; //declarando ponteiro para funcao
  
  pF = incrementar; //atribuindo a funcao ao ponteiro

  int r=0;
   
  // r = incrementar(10); //1ª forma
  // r = pF(10);          //2ª forma
  r = (*pF)(10);          //3ª forma (é preferível usar essa)

  printf("\n%d \n", r);


  return 0;
}

int incrementar(int a){
  return a+1;
}