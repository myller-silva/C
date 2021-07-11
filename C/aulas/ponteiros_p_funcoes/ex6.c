#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //sleep()

void func1(     void      ); //parametro: void
void funcx(     void      ); //parametro: void
void func2(   void(*)()   ); //parametro: funcao que recebe void e retorna void

int main(int argc, char *argv[]){
  int op, c=0;
  srand(time(NULL));
  
  do{
    op = rand();    
    printf("%d:\top = %d\t=>\t", c, op);
    (op%2) ? func2(func1) : func2(funcx);   //"(op%2)?" verifica se op é impar
    c++;
    sleep(2);
  }while(c<10);
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