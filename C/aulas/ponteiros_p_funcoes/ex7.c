#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <unistd.h> //sleep()

void soma(int a, int b, int *r);
void sub(int a, int b, int *r);
void mult(int a, int b, int *r);
void divi(int a, int b, int *r);

void calcular(   void(*pF)(int, int, int*), int a, int b, int *pR   );

typedef void(*Func)();

int main(int argc, char *argv[]){
  if (argc!=4){
    printf("Formato:\n\t%s <num1> <num2> <op>\n", *(argv+0));
    exit(1);
  }
  int n1, n2, r, op, c=0;
  n1 = atoi(    argv[1]   );
  n2 = atoi(  *(argv+2)   );
  op = atoi(  *(argv+3)   ); //obs
  //ponteiro para funcoes: 
  Func v[4] = {soma, sub, mult, divi}; // void (*v[4])() = {soma, sub, mult, divi}; 
  
  // O programa de fato é a partir daqui:
  if(op<4){
    calcular(v[op] , n1, n2, &r);    
  }else{
    printf("Código inválido.\n");
    exit(3);
  }
  printf("r\t=\t%d\n", r);
  // printf("op\t=\t%d\n", op);
  return 0;
}

void soma(int a, int b, int *r){
  *r = a+b;
}
void sub(int a, int b, int *r){
  *r = a-b;
}
void mult(int a, int b, int *r){
  *r = a*b;
}
void divi(int a, int b, int *r){
  if (b==0){
    printf("Divisão invalida. Erro(4)\n");
    exit(4);
  }
  *r = a/b;
}


// obs: quando "calcular" for chamado, 
// deve receber como paramentro: 
// pF que é a funcao referenciada, 
// um valor "a", um valor "b", e um ponteiro;
void calcular(   void(*pF)(int, int, int*), int a, int b, int *pR   ){ //>>> confuso <<< 

  (*pF)(a, b, pR); //chamando a funcao refenrenciada com os parametros recebidos
}
