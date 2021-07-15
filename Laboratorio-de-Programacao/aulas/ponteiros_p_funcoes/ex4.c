#include <stdio.h>

void func1(     void      ); //parametro: void
void funcx(     void      );
void func2(   void(*)()   ); //parametro: funcao que recebe void e retorna void

int main(){
  func2(func1);
  func2(funcx);
  
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