#include <stdio.h>

int incrementar(int a);

int main(){
  // int (*pF)(int) = NULL;
  int r=0;
  void (*pF)();  

  pF = (void(*)()) incrementar; //converter usando cast 
  r = ( (int (*)(int)) pF)(10); //voltar o formato; obs: atenção aos parenteses

  printf("\n%d \n", r);
  
  return 0;
}

int incrementar(int a){
  return a+1;
}