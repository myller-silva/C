#include <stdio.h>
#include <stdlib.h>

void func1(     void      ); //parametro: void
void funcx(     void      );
void func2(   void(*)()   ); //parametro: funcao que recebe void e retorna void

int main(int argc, char *argv[]){

  int op = atoi(  *(argv+1)  );

  (op%2) ? func2(func1):func2(funcx); //(op%2)? verifica se é impar
  
  return 0;
}





void func1(){
  printf("Oi, sou a função 1.\n");
}
void funcx(){
  printf("Olá, mundo!\n");
}
void func2(   void(*pF)(void)   ){
  (*pF)();
}